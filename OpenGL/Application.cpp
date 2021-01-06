
#define GLEW_STATIC

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

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
        -0.5, -0.5, 0,
        0, 0.5, 0,
        0.5, -0.5, 0
    };

    VertexBuffer vb(&vertices, sizeof(vertices));
    VertexArray va;
    VertexBufferLayout layout;
    layout.Push<float>(3);

    va.Bind();
    va.AddBuffer(vb, layout);

    Shader myShader("resource/shader/Basic.shader");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        va.Bind();
        myShader.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        va.UnBind();
        myShader.UnBind();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}