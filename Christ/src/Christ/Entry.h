#pragma once
#include "Christ/Application.h"
#include "Christ/Log.h"

#include "Christ/Event/EventBase.h"
#include "Christ/Event/WindowEvent.h"

extern Christ::Application* CreateApplication();

bool OnClose(Christ::EventBase& e)
{
	LOG_INFO("OnClose Run");
	return false;
}

int main()
{
	LOG_INIT;
	LOG_CORE_INFO("Entry Main Function");

	Christ::WindowClosedEvent e;
	//Christ::EventDispatcher dispatcher(e);
	//dispatcher.Dispatch<Christ::WindowClosedEvent>(OnClose);

	Christ::Application* app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}
