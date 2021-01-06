#include "VertexBuffer.h"

#include "GL/glew.h"

VertexBuffer::VertexBuffer(const void* buffer, const size_t size)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}