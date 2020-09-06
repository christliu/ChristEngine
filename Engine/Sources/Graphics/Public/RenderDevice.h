
class RenderDevice
{
public:
	RenderDevice();

	virtual int GetDeviceTag() = 0;
};

extern RenderDevice *GRenderDevice;