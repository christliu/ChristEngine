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

	private:
		WindowBase* m_window;

	};

	static Application* CreateApplication();
}