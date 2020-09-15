#include <windows.h>
#include "Client/GameApp.h"


class Win32Game : public GameApp
{
public:
	Win32Game(const char* clsname, const char* titlename);
	void Run();

	virtual void* GetContext();

private:
	HWND mWindow;
};