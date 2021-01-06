#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();

	void AddBuffer(VertexBuffer& vb, VertexBufferLayout& layout);
	void Bind();
	void UnBind();
private:
	unsigned int m_id;
};