#include "RenderDevice.h"

RenderDevice* GRenderDevice = nullptr;

RenderDevice::RenderDevice()
{
	GRenderDevice = this;
}