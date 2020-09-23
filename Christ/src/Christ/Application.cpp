#include "Pch.h"
#include "Application.h"
//#include "Platform/Windows/WinWindow.h"

namespace Christ
{

	Application::Application()
	{
		m_window = WindowBase::Create();
	}

	void Application::Run()
	{
		while (1)
		{
			m_window->Tick();
		};
	}
}