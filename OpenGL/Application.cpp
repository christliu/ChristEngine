
#define GLEW_STATIC

// external header file
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

// opengl core
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Renderer.h"

// examples
#include "ExampleClear.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 960, "Hello World", NULL, NULL);
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

    std::cout << "CheckVersion" << std::endl;
    IMGUI_CHECKVERSION();

    std::cout << glGetString(GL_VERSION) << std::endl;
 
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();

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

    ExampleBase* current;
    ExampleMenu *menu = new ExampleMenu(current);
    current = menu;

    menu->AddExample<ExampleClear>("ClearColor");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 1.0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        {
            //render.Render(va, eb, myShader);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Demo window");

        if (current != menu)
        {
            if (ImGui::Button("<- back"))
            {
                delete current;
                current = menu;
            }
        }
        current->OnImGuiRender();
        current->Render();

        //if(ImGui::Button("Hello!"))
        //{
        //    std::cout << "Hello Demo Run" << std::endl;
        //};

       /* static float rotation = 0.0;
        ImGui::SliderFloat("rotation", &rotation, 0, 2 * 3.14);*/
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}