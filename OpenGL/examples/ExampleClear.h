#pragma once
#include "ExampleBase.h"

class ExampleClear : public ExampleBase
{
public:
	ExampleClear(): ExampleBase(), r(0), g(0), b(0), a(1) {};
	void Init() override;
	void OnImGuiRender() override;

	void Render() override;

private:
	float r, g, b, a;
};