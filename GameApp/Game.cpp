#include "Christ.h"
#include "Christ/Log.h"


class MyApplication: public Christ::Application
{
};



Christ::Application* CreateApplication()
{
	return new MyApplication();
}