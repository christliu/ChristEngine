#pragma once

#include "ExampleBase.h"

#include <memory>

class Shader;
class VertexBuffer;
class IndexBuffer;
class VertexArray;
class Texture;
class Renderer;

class ExampleVertexLayout : public ExampleBase
{
public:
	ExampleVertexLayout()
	{
		Init();
	};

	void Init();
	void Render();
	void OnImGuiRender();

private:
	std::unique_ptr<Shader> m_pShader;
	std::unique_ptr<VertexBuffer> m_pVB;
	std::unique_ptr<IndexBuffer> m_pEB;
	std::unique_ptr<VertexArray> m_pVA;

	std::unique_ptr<Texture> m_pTexture;
	std::unique_ptr<Renderer> m_pRenderer;
};