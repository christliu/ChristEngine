#pragma once

#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 position = { 0, 0, 0 }, glm::vec3 up = {0, 1, 0}, float yaw = 0.0f, float pitch = 0.0f) :
		m_Pos(position),WorldUp(up), m_Front(glm::vec3(0, 0, -1)), m_Yaw(yaw), m_Pitch(pitch)
	{

	};

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(m_Pos, m_Pos + m_Front, m_Up);
	}

	void UpdateCameraVectors()
	{
		float y = sin(glm::radians(m_Yaw));
		float x = cos(glm::radians(m_Pitch)) * cos(glm::radians(m_Yaw));
		float z = cos(glm::radians(m_Pitch)) * sin(glm::radians(m_Yaw));
		m_Front = glm::normalize(glm::vec3(x, y, z));
	}

private:
	glm::vec3 m_Pos;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
	glm::vec3 m_Front;
	float m_Pitch, m_Yaw;

	glm::vec3 WorldUp;

};