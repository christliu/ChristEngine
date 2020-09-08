
#include "OpenGLDevice.h"
#include <stdio.h>

void OpenGLDevice::Initialize()
{
	printf("OpenGLDevice Initialize");
	// TODO: dispatch job to render thread.
	printf("tag %d\n", GRenderDevice->GetDeviceTag());
}

void OpenGLDevice::Finalize()
{
	
}