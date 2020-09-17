#include "client/ClientEngine.h"
// TODO: Remove Device Impl here
#include "OpenGLDevice.h"
#include "Client/GameApp.h"

ClientEngine* GClientEngine = nullptr;

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


void ClientEngine::Draw()
{
	GRenderDevice->Draw();
}