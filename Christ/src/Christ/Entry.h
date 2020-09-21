#pragma once
#include "Christ/Application.h"
#include "Christ/Log.h"

extern Christ::Application* CreateApplication();

int main()
{
	Christ::Log::init();
	LOG_CORE_INFO("Entry Main Function");
	Christ::Application* app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}
