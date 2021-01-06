
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include<GL/glew.h>

#include "Shader.h"

unsigned int CreateShader(const char* vertexSrc, const char* fragSrc)
{
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return -1;
	}
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSrc, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		return -1;
	}

	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return -1;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

Shader::Shader(const char* path)
{
	std::ifstream fs;
	fs.open(path, std::fstream::in);

	std::string line;

	std::stringstream srcstream[2];
	int type = -1;
	while (getline(fs, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = 0;
			}
			else if(line.find("fragment") != std::string::npos)
			{
				type = 1;
			}
		}
		else
		{
			if (type != -1)
			{
				srcstream[type] << line << std::endl;
			}
		}
	}

	fs.close();

	std::cout << "VertexShader" << std::endl;
	std::cout << srcstream[0].str() << std::endl;

	m_shaderId = CreateShader(srcstream[0].str().c_str(), srcstream[1].str().c_str());
}

void Shader::Bind()
{
	glUseProgram(m_shaderId);
}

void Shader::UnBind()
{
	glUseProgram(0);
}