#pragma once
#include "Pch.h"
#include "Christ/Core.h"
#include "Christ/WindowBase.h"

namespace Christ
{
	class CHRIST_API WinWindow : public WindowBase
	{
	public:
			WinWindow(const WindowProp& prop);
			void Initialize(const WindowProp &prop);
			void SetEventCallback(const EventFn& f);
			void Tick();

	protected:
		HWND m_HWND;

	private:
		unsigned int m_Width, m_Height;
		const char* m_Title;

		static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		LRESULT CALLBACK OnWinMsg(UINT msg, WPARAM wParam, LPARAM lParam);

	};
}