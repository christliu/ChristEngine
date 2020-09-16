#include <windows.h>
#include <GL/GL.h>

#include <stdio.h>
#include <iostream>
using namespace std;

#pragma comment (lib, "opengl32.lib")

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


HWND CreateGameWindow(const char* clsname, const char* titlename, int w, int h)
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
		100, 100, w, h,
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


bool InitOpenGL(HWND hWnd)
{

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
		PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
		32,                   // Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                   // Number of bits for the depthbuffer
		8,                    // Number of bits for the stencilbuffer
		0,                    // Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	int format = ChoosePixelFormat(GetDC(hWnd), &pfd);
	if(format == 0)
	{
		printf("choose pixel format error!\n");
		return false;
	}

	SetPixelFormat(GetDC(hWnd), format, &pfd);

	HGLRC context = wglCreateContext(GetDC(hWnd));

	wglMakeCurrent(GetDC(hWnd), context);
	MessageBoxA(0,(char*)glGetString(GL_EXTENSIONS), "OPENGL VERSION",0);
	wglDeleteContext(context);
	return true;
}

bool InitOpenGLProper(HWND hWnd)
{
	// 1. create a fake context
	// 2. use fake context to load wglGetProcAddress
	// 3. to get real extension address to init opengl.
	void* ptr = wglGetProcAddress("glAttachShader");
	cout << "before init context address " << ptr << endl;

	// create window
	const char* clsname = "__TEMP";
	const char* titlename = "__TEMP";
	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(nullptr);
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS,
		DefWindowProc,
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
	HWND hWndTemp = CreateWindowEx(
		0,
		clsname,
		titlename,
		WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		100, 100, 500, 400,
		nullptr,
		nullptr,
		hInstance,
		nullptr);
	if (hWndTemp == nullptr)
	{
		::MessageBoxW(nullptr, L"Failed to create window.", L"Error", MB_OK);
		::ExitProcess(127);
	}

	HDC hDC = GetDC(hWndTemp);

	PIXELFORMATDESCRIPTOR FormatDesc;
	memset(&FormatDesc, 0, sizeof(PIXELFORMATDESCRIPTOR));
	FormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	FormatDesc.nVersion = 1;
	FormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	FormatDesc.iPixelType = PFD_TYPE_RGBA;
	FormatDesc.cColorBits = 32;
	FormatDesc.cDepthBits = 0;
	FormatDesc.cStencilBits = 0;
	FormatDesc.iLayerType = PFD_MAIN_PLANE;
	INT PixelFormat = ::ChoosePixelFormat(hDC, &FormatDesc);
	if( !PixelFormat || !::SetPixelFormat(hDC, PixelFormat, &FormatDesc) )
		return false;

	HGLRC context = wglCreateContext(hDC);

	wglMakeCurrent(hDC, context);

	// get address
	ptr = wglGetProcAddress("glAttachShader");
	//printf("after set current context address %ld\n", int64_t(ptr));
	cout << "after set current context address " << ptr << endl;

	HMODULE hOpenGL42 = ::LoadLibrary("opengl32.dll");
	ptr = GetProcAddress(hOpenGL42, "glAttachShader");
	cout << "get proc address " << ptr << endl;

	wglDeleteContext(context);
	ReleaseDC(hWndTemp, hDC);
	DestroyWindow(hWndTemp);
	UnregisterClass(clsname, hInstance);

	return true;

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow("window-test", "opengl-test", 800, 600);

	AllocConsole();
	SetConsoleTitle("ChristEngine Console");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	printf("Windows Init Done\n");
	//InitOpenGL(hWnd);
	InitOpenGLProper(hWnd);
	MSG msg;
	while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
		DispatchMessage( &msg );
	return 0;
}