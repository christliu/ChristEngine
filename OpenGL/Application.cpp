
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
#include "Camera.h"

// examples
#include "ExampleClear.h"
#include "ExampleVertexLayout.h"
#include "ExampleCamera.h"

bool firstMouse = true;
float lastX = 1280 / 2.0f;
float lastY = 960 / 2.0f;
float xoffset = 0.0f;
float yoffset = 0.0f;

void mouse_callback(GLFWwindow* window, int button, int action, int mods);
void mouse_move(GLFWwindow* window, double xpos, double ypos);

ExampleBase* current;

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

    
    ExampleMenu *menu = new ExampleMenu(current);
    current = menu;

    menu->AddExample<ExampleClear>("ClearColor");
    menu->AddExample<ExampleVertexLayout>("VertexLayout");
    menu->AddExample<ExampleCamera>("Camera");

    glfwSetCursorPosCallback(window, mouse_move);
    glfwSetMouseButtonCallback(window, mouse_callback);

    float deltaTime = 0.0f;
    float lastFrame = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 1.0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
                firstMouse = true;
            }
        }
        current->OnUpdate(window, deltaTime);
        //current->OnMouseMove(xoffset, yoffset);
        current->OnImGuiRender();
        current->Render();

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

void mouse_move(GLFWwindow* window, double xpos, double ypos)
{
    current->mouse_move(window, xpos, ypos);
}

void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
    current->mouse_callback(window, button, action, mods);
}