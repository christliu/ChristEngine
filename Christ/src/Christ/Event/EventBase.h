#pragma once
#include "Pch.h"
#include "Christ/Core.h"
#include <functional>

namespace Christ
{
	enum class EventType
	{
		WindowResize, WindowClosed,
		KeyPressed, KeyReleased,
		MouseClicked, MouseReleased, MouseMoved,
	};

#define EVENT_CLASS_TYPE(x) static EventType GetStaticType() { return EventType::##x; } \
						EventType GetEventType() override {return GetStaticType();} \
						const char* GetName() override { return #x; }

	class CHRIST_API EventBase
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() = 0;
		virtual const char* GetName() = 0;

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(EventBase& e) :m_Event(e) {};

		template<typename T>
		bool Dispatch(EventFn<T> fn)
		{
			if(m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = fn(*(T*)&m_Event);
				return true;
			}
			else
				return false;
		}

	private:
		EventBase& m_Event;

	};
}