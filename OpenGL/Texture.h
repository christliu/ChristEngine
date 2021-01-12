#pragma once

class Texture
{
public:
	Texture(const char* filename, bool isAlpha);

	void Bind();
	void UnBind();
private:
	unsigned int m_id;
	int m_width, m_height, m_channels;
	bool m_isAlpha;
};