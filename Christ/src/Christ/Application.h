#pragma once

#include "Core.h"

#include "WindowBase.h"

namespace Christ
{
	class CHRIST_API Application
	{

	public:
		Application();

		virtual void Run();

		bool OnWindowEvent(EventBase& e);

	private:
		WindowBase* m_window;

		bool m_IsRunning;
	};

	static Application* CreateApplication();
}