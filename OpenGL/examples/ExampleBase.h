#pragma once
#include <vector>
#include <functional>

#include "imgui.h"

class ExampleBase
{
public:
	ExampleBase() 
	{
		Init();
	}

	virtual void Init() {};
	virtual void OnUpdate() {};
	virtual void Render() {};
	virtual void OnImGuiRender() {};

private:
};


class ExampleMenu : public ExampleBase
{
public:
	ExampleMenu(ExampleBase*& current) : ExampleBase(), m_current(current) {}

	void Init() {}

	void Render() {

	}

	void OnImGuiRender() {
		for (auto example : m_Examples)
		{
			if (ImGui::Button(example.first))
			{
				m_current = example.second();
			}
		}
	}

	template<typename T>
	void AddExample(const char* name)
	{
		m_Examples.push_back(std::make_pair(name, []() {return new T(); }));
	}

private:
	std::vector < std::pair < const char*, std::function< ExampleBase*() > >> m_Examples;
	ExampleBase*& m_current;
};