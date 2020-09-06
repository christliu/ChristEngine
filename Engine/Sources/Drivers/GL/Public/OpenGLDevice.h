#include "RenderDevice.h"

class OpenGLDevice : public RenderDevice
{
public:
	OpenGLDevice(){};
	void Initialize();
	void Finalize();

	// TODO: Return String or Enum
	int GetDeviceTag() { return 1;}
private:
};