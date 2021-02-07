#pragma once
#include <vector>
#include <functional>

#include "imgui.h"

class GLFWwindow;

class ExampleBase
{
public:
	ExampleBase()
	{
	}

	virtual ~ExampleBase() {};

	virtual void OnUpdate(GLFWwindow* window, float deltaTime) {};
	virtual void OnMouseMove(float xoffset, float yoffset) {};
	virtual void mouse_callback(GLFWwindow* window, int button, int action, int mods) {};
	virtual void mouse_move(GLFWwindow* window, double xpos, double ypos) {};
	virtual void Render() {};
	virtual void OnImGuiRender() {};

private:
};


class ExampleMenu : public ExampleBase
{
public:
	ExampleMenu(ExampleBase*& current) : ExampleBase(), m_current(current) {}


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