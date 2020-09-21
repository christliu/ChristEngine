#pragma once

#include "Core.h"

namespace Christ
{
	class CHRIST_API Application
	{

	public:
		Application(){};

		virtual void Run();

	};

	static Application* CreateApplication();
}