#pragma once

#include "EventBase.h"

namespace Christ
{
	class CHRIST_API WindowClosedEvent : public EventBase
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WindowClosed)

	};
}