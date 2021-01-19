#include "ExampleClear.h"
#include<GL/glew.h>


void ExampleClear::OnImGuiRender()
{
	ImGui::SliderFloat("r", &r, 0, 1);
	ImGui::SliderFloat("g", &g, 0, 1);
	ImGui::SliderFloat("b", &b, 0, 1);
	ImGui::SliderFloat("a", &a, 0, 1);
}

void ExampleClear::Render()
{
	glClearColor(r, g, b, a);
}
