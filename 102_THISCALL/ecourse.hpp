/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : All C++ Courses
* MODULE     : ecourse.hpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#ifndef ECOURSE_CO_KR
#define ECOURSE_CO_KR

#if _MSC_VER > 1000
#pragma  once
#endif

#ifdef UNICODE
#undef _UNICODE
#undef UNICODE
#endif

#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <tchar.h>
#include <map>
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
using namespace std;

namespace ecourse
{
	namespace basic
	{
		int ec_next_int()
		{
			static int n = 0;
			++n;
			return n;
		}
		void ec_set_cursor(short x, short y)
		{
			COORD coord = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		class Color
		{
			int _red, _green, _blue;
		public:
			Color(int r = 0, int g = 0, int b = 0) : _red(r), _green(g), _blue(b) {}
			inline int red()   const { return _red; }
			inline int green() const { return _green; }
			inline int blue()  const { return _blue; }
			inline static Color& redColor()
			{
				static Color red(255, 0, 0);
				return red;
			}
			inline static Color& greenColor()
			{
				static Color green(0, 255, 0);
				return green;
			}
			inline static Color& blueColor()
			{
				static Color blue(0, 0, 255);
				return blue;
			}
		};
	}
	namespace message
	{
		void ec_process_message()
		{
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

#ifdef AUTO_MESSAGE_LOOP
		class __GlobalMessageLoop
		{
		public:
			__GlobalMessageLoop() { srand(time(0)); }
			~__GlobalMessageLoop() { IoProcessMessage(); }
		} _messageLoop;
#endif
	}
	namespace timer
	{
		typedef void(*ec_TIMER_HANDLER)(int);
		map<int, ec_TIMER_HANDLER> timer_map;

		int CALLBACK _InternalTimerProcedure(HWND hwnd, UINT msg, UINT_PTR id, DWORD)
		{
			if (timer_map[id])
				timer_map[id](id);
			return 0;
		}

		int ec_set_timer(int ms, ec_TIMER_HANDLER handler)
		{
			int id = SetTimer(0, 0, ms, (TIMERPROC)_InternalTimerProcedure);
			timer_map[id] = handler;
			return id;
		}

		void ec_kill_timer(int id)
		{
			KillTimer(0, id);
			timer_map.erase(id);
		}
	}
	namespace gui
	{
		typedef int(*ec_MESSAGE_HANDLER)(int, int, int, int);

		map<HWND, ec_MESSAGE_HANDLER> proc_map;

		LRESULT CALLBACK _InternalMessageProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
		{
			if (msg == WM_CREATE)
			{
				ec_MESSAGE_HANDLER handler = (ec_MESSAGE_HANDLER)((LPCREATESTRUCT)lp)->lpCreateParams;
				proc_map[hwnd] = handler;
			}

			if (proc_map[hwnd])
				proc_map[hwnd]((int)hwnd, msg, wp, lp);

			if (msg == WM_DESTROY)
			{
				ExitProcess(0);
			}
			return DefWindowProc(hwnd, msg, wp, lp);
		}

		//----------------------------------------------------------------------------------------------
		int ec_make_window(ec_MESSAGE_HANDLER proc, string title = "S/W Design Pattern(C++)")
		{
			WNDCLASS wc = { 0 };
			wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			wc.hCursor = LoadCursor(0, IDC_ARROW);
			wc.hIcon = LoadIcon(0, IDI_WINLOGO);
			wc.hInstance = (HINSTANCE)GetModuleHandle(0);
			wc.lpfnWndProc = _InternalMessageProcedure;

			ostringstream oss;
			oss << "ec_GUI" << basic::ec_next_int();

			string cname = oss.str();
			wc.lpszClassName = cname.c_str();
			RegisterClass(&wc);

			HWND hwnd = CreateWindow(cname.c_str(), title.c_str(),
				WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT,
				0, 0, 0, 0, (void*)proc);

			ShowWindow(hwnd, SW_SHOW);
			return (int)hwnd;
		}

		void ec_set_window_rect(int handle, int x, int y, int w, int h)
		{
			MoveWindow((HWND)handle, x, y, w, h, TRUE);
		}

		void ec_add_child(int parent_handle, int child_handle)
		{
			SetWindowLong((HWND)child_handle, GWL_STYLE, WS_VISIBLE | WS_BORDER | WS_CHILD);
			SetParent((HWND)child_handle, (HWND)parent_handle);
		}
		
		void ec_set_window_color(int handle, const basic::Color& color)
		{
			HBRUSH brush = CreateSolidBrush(RGB(color.red(), color.green(), color.blue()));
			HBRUSH old = (HBRUSH)SetClassLong((HWND)handle, GCL_HBRBACKGROUND, (LONG)brush);
			DeleteObject(old);
			InvalidateRect((HWND)handle, 0, TRUE);
		}
		
	}
	namespace module
	{
#ifdef _WIN32
#define IOEXPORT __declspec(dllexport)
#else
#define IOEXPORT 
#endif

		void* ec_load_module(string path)
		{
			return reinterpret_cast<void*>(LoadLibraryA(path.c_str()));
		}
		void ec_unload_module(void* p)
		{
			FreeLibrary((HMODULE)p);
		}
		void* ec_get_function_address(void* module, string func)
		{
			return reinterpret_cast<void*>(GetProcAddress((HMODULE)module, func.c_str()));
		}
	}
	namespace file
	{
		typedef int(*PFENUMFILE)(string, void*);

		void ec_enum_files(string path, string filter, PFENUMFILE f, void* param)
		{
			BOOL b = SetCurrentDirectory(path.c_str());

			if (b == false)
			{
				cout << "[DEBUG] " << path.c_str() << " directory does not exit" << endl;
				return;
			}
			WIN32_FIND_DATA wfd = { 0 };
			HANDLE h = ::FindFirstFile(filter.c_str(), &wfd);
			do
			{
				if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !(wfd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
				{
					if (f(wfd.cFileName, param) == 0) break;
				}
			} while (FindNextFile(h, &wfd));

			FindClose(h);
		}
	}

	namespace ipc
	{
		typedef int(*IPC_SERVER_HANDLER)(int, int, int);

		IPC_SERVER_HANDLER _proxyServerHandler;

		LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			if (msg >= WM_USER)
				return _proxyServerHandler(msg - WM_USER, wParam, lParam);

			switch (msg)
			{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			}
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}

		HWND MakeWindow(string name, int show)
		{
			HINSTANCE hInstance = GetModuleHandle(0);
			WNDCLASS wc;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			wc.hCursor = LoadCursor(0, IDC_ARROW);
			wc.hIcon = LoadIcon(0, IDI_APPLICATION);
			wc.hInstance = hInstance;
			wc.lpfnWndProc = WndProc;
			wc.lpszClassName = _T("First");
			wc.lpszMenuName = 0;
			wc.style = 0;

			RegisterClass(&wc);

			HWND hwnd = CreateWindowEx(0, _T("First"), name.c_str(), WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);

			ShowWindow(hwnd, show);
			return hwnd;
		}


		void ProcessMessage(IPC_SERVER_HANDLER handler)
		{
			_proxyServerHandler = handler;
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0))
			{
				TranslateMessage(&msg),
					DispatchMessage(&msg);
			}
		}
		//------------------------------------------------------------------
	
		void ec_start_server(string name, IPC_SERVER_HANDLER handler, int show = SW_HIDE)
		{
#ifdef _DEBUG
			printf("[DEBUG] %s Server Start...\n", name.c_str());
#endif

			MakeWindow(name, show);
			ProcessMessage(handler);
		}

		int ec_find_server(string name)
		{
			HWND hwnd = FindWindow(0, name.c_str());

			if (hwnd == 0)
			{
				printf("[DEBUG] 실패 : %s Server를 찾을수 없습니다.\n", name.c_str());
				return -1;
			}
			return (int)hwnd;
		}

		int ec_send_server(int serverid, int code, int param1, int param2)
		{
			return SendMessage((HWND)serverid, code + WM_USER, param1, param2);
		}
		
	}

	using namespace basic;
	using namespace message;
	using namespace timer;
	using namespace gui;
	using namespace module;
	using namespace file;
	using namespace ipc;
}

#endif	// ECOURSE_CO_KR

