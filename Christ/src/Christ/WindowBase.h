
#include "Pch.h"
#include "Core.h"
#include "Christ/Event/EventBase.h"

namespace Christ
{
	struct WindowProp
	{
		const char* title;
		unsigned int width, height;

		WindowProp(const char* t="Christ",
					unsigned int w=1280,
					unsigned int h=720)
			: title(t), width(w), height(h)
		{}

	};
	class CHRIST_API WindowBase
	{
	public:
		using EventFn = std::function<bool(EventBase&)>;

		virtual void SetEventCallback(const EventFn& f) = 0;
		virtual void Tick() = 0;

		static WindowBase* Create(const WindowProp& prop=WindowProp());
	};
}