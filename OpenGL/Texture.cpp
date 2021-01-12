#include "Texture.h"
#include "stb_image.h"
#include <iostream>
#include <string>
#include "GL/glew.h"

Texture::Texture(const char* filename, bool isAlpha):m_isAlpha(isAlpha)
{
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(filename, &m_width, &m_height, &m_channels, 0);
	if (!data)
	{
		std::cout << "File Path Does Not exists" << filename << std::endl;
		system("exit");
	}
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if(m_isAlpha)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
