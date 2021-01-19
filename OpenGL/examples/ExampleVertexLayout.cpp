#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Renderer.h"

#include "ExampleVertexLayout.h"

void ExampleVertexLayout::Init()
{
	m_pShader = std::make_unique<Shader>("resource/shader/Basic.shader");
    m_pTexture = std::make_unique<Texture>("resource/textures/wood.png", false);
    m_pRenderer = std::make_unique<Renderer>();

    float vertices[] = {
       -0.5, -0.5, 0,  0.0f, 0.0f,
       -0.5, 0.5, 0, 0.0f, 1.0f,
       0.5, -0.5, 0, 1.0f, 0.0f,
       0.5, 0.5, 0, 1.0f, 1.0f
    };

    int indices[] = {
        0,1,2,
        1,2,3
    };

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);

    m_pVB = std::make_unique<VertexBuffer>(&vertices, sizeof(vertices));
    m_pEB = std::make_unique<IndexBuffer>(indices, sizeof(indices) / sizeof(int));
    m_pVA = std::make_unique<VertexArray>();

    m_pVA->Bind();
    m_pVA->AddBuffer(*m_pVB.get(), *m_pEB.get(), layout);
}

void ExampleVertexLayout::Render()
{
    m_pRenderer->Render(*m_pVA.get(), *m_pEB.get(), *m_pShader.get());
}

void ExampleVertexLayout::OnImGuiRender()
{
}
