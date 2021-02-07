#include "Camera.h"
#include <iostream>
using namespace std;
float MOVE_SPEED = 2.0f;

void Camera::UpdateYawPitch(float xoffset, float yoffset)
{
	float MouseSensitivity = 0.1f;

	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;
	m_Yaw += xoffset;

	UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
	float y = sin(glm::radians(m_Pitch));
	float x = cos(glm::radians(m_Pitch)) * cos(glm::radians(m_Yaw));
	float z = cos(glm::radians(m_Pitch)) * sin(glm::radians(m_Yaw));
	m_Front = glm::normalize(glm::vec3(x, y, z));

	// 由于opengl采用右手坐标系，z表示的是摄像机朝向的方向，x表示的是摄像机的左边，所以m_Right表示的是-x方向。
	m_Right = glm::normalize(glm::cross(m_Front, WorldUp));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

void Camera::ProcessKeyboard(DIRECTION dir, float delta)
{
	float change = delta * MOVE_SPEED;
	switch (dir)
	{
	case FORWARD:
		m_Pos += m_Front * change;
		break;
	case BACKWARD:
		m_Pos -= m_Front * change;
		break;
	case LEFT:
		m_Pos -= m_Right * change;
		break;
	case RIGHT:
		m_Pos += m_Right * change;
		break;
	default:
		break;
	}
}
