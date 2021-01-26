#include "Camera.h"

void Camera::UpdateCameraVectors()
{
	float y = sin(glm::radians(m_Pitch));
	float x = cos(glm::radians(m_Pitch)) * cos(glm::radians(m_Yaw));
	float z = cos(glm::radians(m_Pitch)) * sin(glm::radians(m_Yaw));
	m_Front = glm::normalize(glm::vec3(x, y, z));

	m_Right = glm::normalize(glm::cross(WorldUp, m_Front));
	m_Up = glm::normalize(glm::cross(m_Front, m_Right));
}
