#include "VertexBuffer.h"

#include "GL/glew.h"

VertexBuffer::VertexBuffer(const void* buffer, const size_t size)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(const int* buffer, int count):m_count(count)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(int), (void*)buffer, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IndexBuffer::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

const int IndexBuffer::GetCount() const
{
	return m_count;
}
