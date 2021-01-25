#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char* path);

	~Shader();

	void Bind();
	void UnBind();

	void SetMatrix4(const char* position, const glm::mat4& matrix);
private:
	unsigned int m_shaderId;
};