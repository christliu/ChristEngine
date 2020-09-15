#include "RenderDevice.h"

RenderDevice* GRenderDevice = nullptr;

RenderDevice::RenderDevice(void* platform_context)
{
	GRenderDevice = this;
}