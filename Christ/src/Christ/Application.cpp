#include "Pch.h"
#include "Application.h"
#include "Log.h"


namespace Christ
{

	Application::Application()
	{
		m_window = WindowBase::Create();
		m_window->SetEventCallback(std::bind(&Application::OnWindowEvent, this, std::placeholders::_1));
		m_IsRunning = true;
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			m_window->Tick();
		};
	}

	bool Application::OnWindowEvent(EventBase& e)
	{
		LOG_INFO("OnWindowEvent {0}", e.GetName());
		m_IsRunning = false;
		return true;
	}
}