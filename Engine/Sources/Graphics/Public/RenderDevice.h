
class RenderDevice
{
public:
	// RenderDevice(){};
	RenderDevice(void* platform_context);

	virtual int GetDeviceTag() = 0;
	virtual void Initialize() = 0;
	virtual void Draw() = 0;
};

extern RenderDevice *GRenderDevice;