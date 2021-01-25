#include "ExampleCamera.h"
#include "Shader.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Renderer.h"

ExampleCamera::ExampleCamera()
{
	m_pShader = std::make_unique<Shader>("resource/shader/BasicCamera.shader");
    float r = 0.5f;

    GLfloat vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,   1,-1, 1,   // v0,v1,v2,v3 (front)
                            1, 1, 1,   1,-1, 1,   1,-1,-1,   1, 1,-1,   // v0,v3,v4,v5 (right)
                            1, 1, 1,   1, 1,-1,  -1, 1,-1,  -1, 1, 1,   // v0,v5,v6,v1 (top)
                           -1, 1, 1,  -1, 1,-1,  -1,-1,-1,  -1,-1, 1,   // v1,v6,v7,v2 (left)
                           -1,-1,-1,   1,-1,-1,   1,-1, 1,  -1,-1, 1,   // v7,v4,v3,v2 (bottom)
                            1,-1,-1,  -1,-1,-1,  -1, 1,-1,   1, 1,-1 }; // v4,v7,v6,v5 (back)

	//绘制 点得索引 
    int indices[] = { 0, 1, 2,   2, 3, 0,      // front
                           4, 5, 6,   6, 7, 4,      // right
                           8, 9,10,  10,11, 8,      // top
                          12,13,14,  14,15,12,      // left
                          16,17,18,  18,19,16,      // bottom
                          20,21,22,  22,23,20 };    // back


    VertexBufferLayout layout;
    layout.Push<float>(3);
    //layout.Push<float>(2);

    m_pVB = std::make_unique<VertexBuffer>(&vertices, sizeof(vertices));
    m_pEB = std::make_unique<IndexBuffer>(indices, sizeof(indices) / sizeof(int));
    m_pVA = std::make_unique<VertexArray>();

    m_pVA->Bind();
    m_pVA->AddBuffer(*m_pVB.get(), *m_pEB.get(), layout);

    r_v = -5.0f;
}

void ExampleCamera::Render()
{
    const int WIDTH = 1280;
    const int HEIGHT = 960;

    glm::mat4 model = glm::mat4(1.0f);

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, r_v));

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(45.0f, float(WIDTH) / float(HEIGHT), 0.1f, 100.0f);

    m_pShader->SetMatrix4("model", model);
    m_pShader->SetMatrix4("view", view);
    m_pShader->SetMatrix4("projection", projection);

    m_pRenderer->Render(*m_pVA.get(), *m_pEB.get(), *m_pShader.get());
}

void ExampleCamera::OnImGuiRender()
{
    ImGui::SliderFloat("r", &r_v, -10.0f, 10.0f);
}
