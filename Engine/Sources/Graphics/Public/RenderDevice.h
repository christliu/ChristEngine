
class RenderDevice
{
public:
	RenderDevice();

	virtual int GetDeviceTag() = 0;
	virtual void Initialize() = 0;
};

extern RenderDevice *GRenderDevice;