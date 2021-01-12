
#define GLEW_STATIC

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Renderer.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum res = glewInit();
    if (res != GLEW_OK)
        return -1;

    std::cout << glGetString(GL_VERSION) << std::endl;

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

    VertexBuffer vb(&vertices, sizeof(vertices));
    IndexBuffer eb(indices, sizeof(indices) / sizeof(int));
    VertexArray va;
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);

    va.Bind();
    va.AddBuffer(vb, eb, layout);

    Shader myShader("resource/shader/Basic.shader");

    Texture texture("resource/textures/wood.png", false);

    Renderer render;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        {
            render.Render(va, eb, myShader);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}