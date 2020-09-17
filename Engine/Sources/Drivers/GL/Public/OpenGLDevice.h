#include "RenderDevice.h"

class OpenGLDevice : public RenderDevice
{
public:
	// OpenGLDevice() {};
	OpenGLDevice(void* platform_context);
	void Initialize();
	void Finalize();

	// TODO: Return String or Enum
	int GetDeviceTag() { return 1;}
private:
	//void LoadOpenGL();
	void* context;
};