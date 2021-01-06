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
	for (int i = 0; i < elems.size(); i++)
	{
		glVertexAttribPointer(i, elems[i].count, elems[i].type, false, layout.GetStride(), 0);
		glEnableVertexAttribArray(0);
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