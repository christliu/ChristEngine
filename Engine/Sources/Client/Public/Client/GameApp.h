
class GameApp
{
public:
	GameApp();

	virtual void Run() = 0;
	virtual void* GetContext() = 0;
};

extern GameApp* GApp;