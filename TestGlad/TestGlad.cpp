
#include <stdio.h>
#include <windows.h>

//#include <GL/GL.h>
#include "glad/glad.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void LoadGL();

//int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd)
int main()
{
	MSG msg = { 0 };
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;

	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(nullptr);
	wc.hInstance = (HINSTANCE)::GetModuleHandle(nullptr);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = L"oglversionchecksample";
	wc.style = CS_OWNDC;
	if (!RegisterClass(&wc))
		return 1;
	CreateWindowW(wc.lpszClassName, L"openglversioncheck", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 640, 480, 0, 0, hInstance, 0);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
		DispatchMessage(&msg);

	return 0;
}


void FirstCreate(HWND hWnd)
{
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
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

	HDC ourWindowHandleToDeviceContext = GetDC(hWnd);

	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
	SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

	HGLRC ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
	wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

	LoadGL();

//	MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);

	//wglMakeCurrent(ourWindowHandleToDeviceContext, NULL); Unnecessary; wglDeleteContext will make the context not current
	//wglDeleteContext(ourOpenGLRenderingContext);
}

void LoadGL()
{
	if (!gladLoadGL()) {
		printf("Something went wrong!\n");
		return;
	}
	printf("OpenGL Load by Gload %d.%d\n", GLVersion.major, GLVersion.minor);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		FirstCreate(hWnd);
	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}

//
//int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
//{
//    // .. setup the context
//
//    if (!gladLoadGL()) {
//        printf("Something went wrong!\n");
//        return -1;
//    }
//    printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);
//    system("pause");
//    return 0;
//    // .. render here ..
//
//}