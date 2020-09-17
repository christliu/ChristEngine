#include "RenderDevice.h"
#include <windows.h>
#include <GL/GL.h>

class OpenGLDevice : public RenderDevice
{
public:
	OpenGLDevice(void* platform_context);
	void Initialize();
	void Finalize();

	// TODO: Return String or Enum
	int GetDeviceTag() { return 1;}

	void Draw();
private:
	void CreateOpenGLContext();
	void DynamicLoadOpenGL();
	void* _platform_context;

	HGLRC _context;
};