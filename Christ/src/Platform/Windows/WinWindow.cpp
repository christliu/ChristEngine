#include "Pch.h"
#include "WinWindow.h"

#include <Windows.h>

namespace Christ {

	WindowBase* WindowBase::Create(const WindowProp& prop)
	{
		return new WinWindow(prop);
	}

	LRESULT CALLBACK WinWindow::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		WinWindow* pThis;

		if ( msg == WM_NCCREATE)
		{
			pThis = static_cast<WinWindow*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

			SetLastError(0);
			if (!SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis)))
			{
				if (GetLastError() != 0)
					return FALSE;
			}
		}
		else
		{
			pThis = reinterpret_cast<WinWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		}

		int result = DefWindowProc(hwnd, msg, wParam, lParam);
		return result;
	}

	WinWindow::WinWindow(const WindowProp& prop)
	{
		Initialize(prop);
	}

	void WinWindow::SetEventCallback(const EventFn& f)
	{

	}

	void WinWindow::Initialize(const WindowProp& prop)
	{
		m_Width = prop.width;
		m_Height = prop.height;
		m_Title = prop.title;

		const char* clsname = "christ window";

		HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(nullptr);
		WNDCLASSEX wcex =
		{
			sizeof(WNDCLASSEX),
			CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS,
			(WNDPROC)WndProc,
			0, 0, hInstance,
			nullptr,
			nullptr,
			nullptr,
			nullptr, clsname,
			nullptr
		};
		if (!::RegisterClassEx(&wcex))
		{
			::MessageBoxW(nullptr, L"Failed to register window.", L"Error", MB_OK);
			::ExitProcess(127);
		}
		HWND hWnd = CreateWindowEx(
			0,
			clsname,
			m_Title,
			WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
			0, 0, m_Width, m_Height,
			nullptr,
			nullptr,
			hInstance,
			this);
		if (hWnd == nullptr)
		{
			::MessageBoxW(nullptr, L"Failed to create window.", L"Error", MB_OK);
			::ExitProcess(127);
		}
		::ShowWindow(hWnd, SW_SHOW);

		m_HWND = hWnd;
	}

	void WinWindow::Tick()
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}