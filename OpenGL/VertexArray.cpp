#include "VertexArray.h"
#include "GL/glew.h"

VertexArray::VertexArray()
{
	glGenBuffers(1, &m_id);
}

void VertexArray::AddBuffer(VertexBuffer& vb, VertexBufferLayout& layout)
{
	vb.Bind();
	const auto& elems = layout.GetElems();
	unsigned int offset = 0;
	for (int i = 0; i < elems.size(); i++)
	{
		glVertexAttribPointer(i, elems[i].count, elems[i].type, false, layout.GetStride(), (void*)offset);
		offset += elems[i].GetSize();
		glEnableVertexAttribArray(i);
	}
}

void VertexArray::AddBuffer(VertexBuffer& vb, IndexBuffer& eb, VertexBufferLayout& layout)
{
	vb.Bind();
	eb.Bind();
	const auto& elems = layout.GetElems();
	unsigned int offset = 0;
	for (int i = 0; i < elems.size(); i++)
	{
		glVertexAttribPointer(i, elems[i].count, elems[i].type, false, layout.GetStride(), (void*)offset);
		offset += elems[i].GetSize();
		glEnableVertexAttribArray(i);
	}
}

void VertexArray::Bind()
{
	glBindVertexArray(m_id);
}


void VertexArray::UnBind()
{
	glBindVertexArray(0);
}