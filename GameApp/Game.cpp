#include "Christ.h"
#include "Christ/Log.h"


class MyApplication: public Christ::Application
{
public:
	void Run() override
	{
		LOG_ERROR("MyApplication Is Running");
		while (1);
	}
};

Christ::Application* CreateApplication()
{
	return new MyApplication();
}