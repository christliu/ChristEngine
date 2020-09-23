#include "Christ.h"
#include "Christ/Log.h"
#include "Christ/Event/WindowEvent.h"


class MyApplication: public Christ::Application
{
};

bool OnClose(Christ::EventBase& e)
{
	LOG_INFO("OnClose Run");
	return false;
}

Christ::Application* CreateApplication()
{
	Christ::WindowClosedEvent e;
	Christ::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Christ::WindowClosedEvent>(OnClose);
	return new MyApplication();
}