#include <iostream>
#include <functional>

#include <Windows.h>
#include <gl/GL.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

HWND doCreateWindow()
{
	const char* clsname = "christ window";
	const char* title = "testwindow";
	const int width = 800, height = 600;

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
		title,
		WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		0, 0, width, height,
		nullptr,
		nullptr,
		hInstance,
		NULL);
	if (hWnd == nullptr)
	{
		::MessageBoxW(nullptr, L"Failed to create window.", L"Error", MB_OK);
		::ExitProcess(127);
	}
	::ShowWindow(hWnd, SW_SHOW);
	return hWnd;
}

int main()
{
	HWND hwnd = doCreateWindow();
	MSG msg;

	// Every Frame handle all windows messages.
	while (GetMessage(&msg, hwnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}