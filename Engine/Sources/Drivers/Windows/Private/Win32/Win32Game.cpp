
#include <windows.h>
#include "ChristEngineWin32.h"
#include "Win32Game.h"
#include "Client/ClientEngine.h"
#include <cstdio>

void RunChristGame(const char* clsname, const char* titlename, /*HICON icon,*/ int argc, char** argv)
{
	Win32Game* game = new Win32Game{ clsname, titlename };
	game->Run();
}

static LRESULT CALLBACK GameWindowProc(HWND hwnd, INT32 msg, WPARAM wParam, LPARAM lParam) noexcept
{
	switch(msg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

static HWND CreateGameWindow(const char* clsname, const char* titlename, int w, int h)
{
	//std: class_name = "ChristEngine";
	//std::wstring title_name = L"ChristEngine";
	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(nullptr);
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS,
		(WNDPROC)GameWindowProc,
		0, 0, hInstance,
		nullptr,
		nullptr,
		nullptr,
		nullptr, clsname,
		nullptr
	};
	if (!::RegisterClassEx(&wcex))
	{
		::MessageBoxW(nullptr, L"Failed to create window.", L"Error", MB_OK);
		::ExitProcess(127);
	}
	HWND hWnd = CreateWindowEx(
		0,
		clsname,
		titlename,
		WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		0, 0, w, h,
		nullptr,
		nullptr,
		hInstance,
		nullptr);
	if (hWnd == nullptr)
	{
		::MessageBoxW(nullptr, L"Failed to create window.", L"Error", MB_OK);
		::ExitProcess(127);
	}
	::ShowWindow(hWnd, SW_SHOW);
	return hWnd;
}

Win32Game::Win32Game(const char* clsname, const char* titlename)
	: GameApp{}, mWindow{NULL}
{
	mWindow = CreateGameWindow(clsname, titlename, 1024, 768);

	AllocConsole();
	SetConsoleTitle("ChristEngine Console");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	printf("Windows Init Done\n");

	// init
	new ClientEngine{};
	GClientEngine->Initialize();

}

void Win32Game::Run()
{
	MSG msg = {0};
	while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
		DispatchMessage( &msg );
}


void* Win32Game::GetContext()
{
	return (void*)mWindow;
}