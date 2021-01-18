#pragma once
#include <vector>
#include <GL/glew.h>

struct LayoutElement
{
	unsigned int count;
	unsigned int type;

	const unsigned int GetSize() const
	{
		unsigned int sizePerElems = 0;
		switch (type)
		{
		case GL_FLOAT:
			sizePerElems = sizeof(GLfloat);
			break;

		}
		return sizePerElems * count;
	}

};

class VertexBufferLayout
{
public:
	VertexBufferLayout();

	const std::vector<LayoutElement> GetElems()
	{
		return m_elems;
	}

	const unsigned int GetStride() { return m_stride; }

	template<typename T>
	void Push(unsigned int count)
	{
	}
	
	template<>
	void Push<float>(unsigned int count)
	{
		m_elems.push_back({ count, GL_FLOAT });
		m_stride += count * sizeof(float);
	}

private:
	unsigned int m_stride;
	std::vector<LayoutElement> m_elems;
};