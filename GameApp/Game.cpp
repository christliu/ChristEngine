#include "Christ.h"
#include <iostream>
using namespace std;

class MyApplication: public Christ::Application
{
public:
	void Run() override
	{
		cout << "In MyApplication " << endl;
		while (1);
	}
};

Christ::Application* CreateApplication()
{
	return new MyApplication();
}