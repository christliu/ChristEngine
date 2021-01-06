
#define GLEW_STATIC

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"

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

    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VAO);
    glBindVertexArray( VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray( 0);

    Shader myShader("resource/shader/Basic.shader");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(VAO);
        //glUseProgram(shaderProgram);
        myShader.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        myShader.UnBind();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}