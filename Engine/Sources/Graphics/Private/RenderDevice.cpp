#include "RenderDevice.h"
#include <iostream>
using namespace std;

RenderDevice* GRenderDevice = nullptr;

RenderDevice::RenderDevice(void* platform_context)
{
	GRenderDevice = this;
	cout << "RenderDevice Initialize Run" << endl;
}