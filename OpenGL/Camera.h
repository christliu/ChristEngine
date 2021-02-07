#pragma once

#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum DIRECTION 
{ 
	FORWARD, 
	BACKWARD, 
	LEFT, 
	RIGHT 
};

class Camera
{
public:
	Camera(glm::vec3 position = { 0, 0, 0 }, glm::vec3 up = {0, 1, 0}, float yaw = -90.0f, float pitch = 0.0f) :
		m_Pos(position),WorldUp(up), m_Front(glm::vec3(0, 0, -1)), m_Yaw(yaw), m_Pitch(pitch)
	{
		UpdateCameraVectors();
	};

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(m_Pos, m_Pos + m_Front, m_Up);
	}

	void SetPosition(glm::vec3 position)
	{
		m_Pos = position;
		UpdateCameraVectors();
	}

	void SetYaw(float yaw)
	{
		m_Yaw = yaw;
		UpdateCameraVectors();
	}

	void UpdateYawPitch(float xoffset, float yoffset);

	void UpdateCameraVectors();

	void ProcessKeyboard(DIRECTION dir, float delta);


private:
	glm::vec3 m_Pos;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
	glm::vec3 m_Front;
	float m_Pitch, m_Yaw;

	glm::vec3 WorldUp;

};