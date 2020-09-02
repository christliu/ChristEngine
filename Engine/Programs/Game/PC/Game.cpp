#include <windows.h>
#include <iostream>

// TODO: Compile Macro
#include "ChristEngineWin32.h"

// void RunChristGame(const char* clsname, const char* titlename, HICON icon, int argc, char** argv)

const char* CLASS_NAME = "ChristEngine";
const char* TITLE_NAME = "ChristEngine";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpCmdLine, int nCmdShow)
{
	std::cout << "Hello ChristEngine" << std::endl;
	RunChristGame(CLASS_NAME, TITLE_NAME, 0, NULL);
	return 0;
}