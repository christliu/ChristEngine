#pragma once
#include <memory>
#include "ExampleBase.h"

#include <glm/glm.hpp>

class Shader;
class VertexBuffer;
class IndexBuffer;
class VertexArray;
//class Texture;
class Renderer;
class Camera;


class ExampleCamera : public ExampleBase
{
public:
	ExampleCamera();

	void Render();
	void OnUpdate(GLFWwindow* window, float deltaTime);
	void OnMouseMove(float xoffset, float yoffset);
	void ExampleCamera::OnImGuiRender();

	void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	void mouse_move(GLFWwindow* window, double xpos, double ypos);
private:
	void processInput(GLFWwindow* window, float deltaTime);

private:
	std::unique_ptr<Shader> m_pShader;

	std::unique_ptr<VertexBuffer> m_pVB;
	std::unique_ptr<IndexBuffer> m_pEB;
	std::unique_ptr<VertexArray> m_pVA;

	//std::unique_ptr<Texture> m_pTexture;
	std::unique_ptr<Renderer> m_pRenderer;
	std::unique_ptr<Camera> m_pCamera;

	float camera_x, camera_y, camera_z;
	float yaw;

	glm::vec3 cameraPos;

	bool m_mouseClicked;
	double lastX, lastY;
};