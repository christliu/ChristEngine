
#include "OpenGLDevice.h"
#include <stdio.h>
#include "wglext.h"

#pragma comment (lib, "opengl32.lib")

// HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList) { return __wglCreateContextAttribsARB(hDC, hShareContext, attribList); }
// // wglChoosePixelFormatARB
// BOOL wglChoosePixelFormatARB(HDC hdc, const int* piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats) { return __wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats); }
// // wglSwapIntervalEXT
// BOOL wglSwapIntervalEXT(int interval) { return __wglSwapIntervalEXT(interval); }

typedef HGLRC (WINAPI  * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI  * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

bool firstLoadGL()
{
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
		return false;
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
		return false;
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
	if (!PixelFormat || !::SetPixelFormat(hDC, PixelFormat, &FormatDesc))
		return false;

	HGLRC context = wglCreateContext(hDC);  // tmp context

	wglMakeCurrent(hDC, context);

	// Use define to simplify
	printf("init wgl create context arb\n");
	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");

	wglDeleteContext(context);
	ReleaseDC(hWndTemp, hDC);
	DestroyWindow(hWndTemp);
	UnregisterClass(clsname, hInstance);
	return true;
}


OpenGLDevice::OpenGLDevice(void* platform_context) : RenderDevice(platform_context)
{
	_platform_context = platform_context;
}

void OpenGLDevice::Initialize()
{
	printf("OpenGLDevice Initialize");
	// TODO: dispatch job to render thread.
	printf("tag %d\n", GRenderDevice->GetDeviceTag());

	CreateOpenGLContext();
	DynamicLoadOpenGL();
}

void OpenGLDevice::Finalize()
{
	
}

void OpenGLDevice::DynamicLoadOpenGL()
{

}

void OpenGLDevice::CreateOpenGLContext()
{
	if(!firstLoadGL())
	{
		return;
	}
	HWND window = (HWND)_platform_context;

	HDC hDC = ::GetDC(window);

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

	const int iPixelFormatAttribList[] =
	{
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB, 32,
		WGL_RED_BITS_ARB, 8,
		WGL_GREEN_BITS_ARB, 8,
		WGL_BLUE_BITS_ARB, 8,
		WGL_ALPHA_BITS_ARB, 8,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,
		0 // End of attributes list
	};

	const int gl_attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 2,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		WGL_CONTEXT_FLAGS_ARB,
		WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0
	};

	int iPixelFormat, iNumFormats;
	wglChoosePixelFormatARB(hDC, iPixelFormatAttribList, nullptr, 1, &iPixelFormat, (UINT*)&iNumFormats);

	// PFD seems to be only redundant parameter now
	SetPixelFormat(hDC, iPixelFormat, &FormatDesc);

	_context = wglCreateContextAttribsARB(hDC, nullptr, gl_attribs);

	wglMakeCurrent(hDC, _context);

}

