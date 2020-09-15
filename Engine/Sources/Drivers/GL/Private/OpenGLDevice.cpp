
#include "OpenGLDevice.h"
#include <stdio.h>

OpenGLDevice::OpenGLDevice(void* platform_context)
{
	context = platform_context;
}

void OpenGLDevice::Initialize()
{
	printf("OpenGLDevice Initialize");
	// TODO: dispatch job to render thread.
	printf("tag %d\n", GRenderDevice->GetDeviceTag());
}

void OpenGLDevice::Finalize()
{
	
}