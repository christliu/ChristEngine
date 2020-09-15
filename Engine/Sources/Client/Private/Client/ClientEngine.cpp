#include "client/ClientEngine.h"
// TODO: Remove Device Impl here
#include "OpenGLDevice.h"
#include "Client/GameApp.h"

ClientEngine* GClientEngine = nullptr;
//extern GameApp* GApp;

ClientEngine::ClientEngine()
{
	GClientEngine = this;
}


void ClientEngine::Initialize()
{
	// Init Device
	new OpenGLDevice{GApp->GetContext()};
	
	GRenderDevice->Initialize();
}