#pragma once

class VertexBuffer
{
public:
	VertexBuffer(const void* buffer, const size_t size);

	void Bind();
	void UnBind();
private:
	unsigned int m_id;
};