// MODULE  : cmc.h
// COMMENT : 
// EMAIL   : smkang @ codenuri.co.kr
// HOME    : www.ecourse.co.kr
// VERSION : 3.0
// DATE    : 2023.07

#pragma once

#include <iostream>
#include <iterator>
#include <sstream>
#include <chrono>
#include <functional>
#include <string_view>
#include <source_location>
#include <ranges>

// + + + + + + + + + + + + + + + + + + + + +
// std::print
// C++20/23
#ifdef __has_include
#	if __has_include(<print>)    
#		include <print>
#	else
#include <format>

namespace std
{
	template<class... Args>
	inline void print(std::string_view fmt, const Args&... args)
	{
		auto s = std::vformat(fmt, std::make_format_args(args...));
		std::cout << s;
	}
	template<class... Args>
	inline void println(std::string_view fmt, const Args&... args)
	{
		auto s = std::vformat(fmt, std::make_format_args(args...));
		std::cout << s << '\n';
	}
}
#	endif
#endif



// + + + + + + + + + + + + + + + + + + + + +
// function_name()
//
std::string function_name(std::source_location loc = std::source_location::current())
{
	std::string name = loc.function_name();

	std::istringstream iss(name);
	std::ostringstream oss;
	std::string s;

	while (iss >> s)
	{
		// "foo(void)" => "foo()" in cl compiler
		if (s.size() > 6 && s.substr(s.size() - 6, 6) == "(void)") // foo(void)
		{
			s.replace(s.size() - 6, 6, "()");
			s.shrink_to_fit();
		}
		if (s != "__cdecl" && s != "__stdcall" && s != "__fastcall" && s != "__thiscall" && s != "thiscall")
			oss << s << " ";
	}
	return oss.str();
}

// + + + + + + + + + + + + + + + + + + + + +
// show implementation

// usage
// show(v)
// show(v.begin(), v.end())
// show(v, "v");
// show(v.begin(), v.end(), "first ~ last")
// show(v.begin(), v.end(), "first, "last")
// show_with_name(v)
// show_with_name(v.begin(), v.end())

template<std::input_iterator T>
void __show_element(T first, T last)
{
	if (first == last) return;

	std::print("{}", *first);

	while (++first != last)
		std::print(", {}", *first);
}

template<std::ranges::range T>
void show(const T& cont, std::string name = "")
{
	if (name != "")
		std::print("{} : ", name);

	std::print("[ ");
	__show_element(std::begin(cont), std::end(cont));
	std::println(" ]");
}

template<std::input_iterator T>
void show(T first, T last, std::string_view sfirst = "", std::string_view slast = "")
{
	if (sfirst != "")
		std::print("{0} ", sfirst);

	if (slast != "")
		std::print("~ {0} ", slast);

	if (sfirst != "" || slast != "")
		std::print(": ", slast);

	std::print("[ ");
	__show_element(first, last);
	std::println(" ]");
}

// show_with_name macro
#define CONVERT_VARIABLE_TO_STRING(Variable) (#Variable)

#define EXPAND( x ) x
#define GET_COUNT_VA_ARGS(...) EXPAND(GET_COUNT_VA_ARGS_IMPL(__VA_ARGS__, 5,4,3,2,1))
#define GET_COUNT_VA_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N

#define MACRO_DISPATCHER(func, ...)       MACRO_DISPATCHER_(func, GET_COUNT_VA_ARGS(__VA_ARGS__))
#define MACRO_DISPATCHER_(func, nargs)    MACRO_DISPATCHER__(func, nargs)
#define MACRO_DISPATCHER__(func, nargs)   func ## nargs

// 2. show macro
#define show_with_name(...) MACRO_DISPATCHER(show_with_name, __VA_ARGS__)(__VA_ARGS__)
#define show_with_name1(container)   show(container, #container)
#define show_with_name2(first, last) show(first, last, #first, #last )


// + + + + + + + + + + + + + + + + + + + + +
// value_category() macro
//
// usage : auto vc = value_category(expression);
//         std::string_view = to_string(vc);

enum class VALUE_CATEGORY { lvalue, xvalue, prvalue };

#define value_category(...)																\
	  std::is_lvalue_reference_v<decltype((__VA_ARGS__))> ? VALUE_CATEGORY::lvalue :	\
	( std::is_rvalue_reference_v<decltype((__VA_ARGS__))> ? VALUE_CATEGORY::xvalue : VALUE_CATEGORY::prvalue );

std::string_view to_string(VALUE_CATEGORY vc)
{
	if (vc == VALUE_CATEGORY::lvalue)
		return std::string_view{ "lvalue" };
	else if ( vc == VALUE_CATEGORY::xvalue )
		return std::string_view{ "rvalue(xvalue)" };
	return std::string_view{ "rvalue(prvalue)" };
}


// + + + + + + + + + + + + + + + + + + + + +
// debug_alloc<T>
//

template<typename T>
class debug_alloc
{
public:
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(debug_alloc<U>&) {}

	T* allocate(std::size_t sz)
	{
		void* ptr = malloc(sizeof(T) * sz);
		std::println("allocate : {}, {} cnts", static_cast<void*>(ptr), sz);
		return static_cast<T*>(ptr);
	}
	void deallocate(T* ptr, std::size_t sz)
	{
		std::println("deallocate : {}, {} cnts", static_cast<void*>(ptr), sz);
		free(ptr);
	}
};

template<typename T>
bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2) { return true; }

template<typename T>
bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2) { return false; }


// + + + + + + + + + + + + + + + + + + + + +
// chronometry() & stop_watch
//
class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	stop_watch sw(true);
	return std::invoke(std::forward<F>(f), std::forward<Types>(args)...);
}

