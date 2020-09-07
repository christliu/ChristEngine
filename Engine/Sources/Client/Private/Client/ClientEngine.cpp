#include "client/ClientEngine.h"
// TODO: Remove Device Impl here
#include "OpenGLDevice.h"

ClientEngine* GClientEngine = nullptr;

ClientEngine::ClientEngine()
{
	GClientEngine = this;
}


void ClientEngine::Initialize()
{
	// Init Device
	new OpenGLDevice{};
}