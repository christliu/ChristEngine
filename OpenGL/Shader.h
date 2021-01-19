#pragma once

class Shader
{
public:
	Shader(const char* path);

	~Shader();

	void Bind();
	void UnBind();
private:
	unsigned int m_shaderId;
};