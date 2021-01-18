#pragma once

class VertexBuffer
{
public:
	VertexBuffer(const void* buffer, const size_t size);
	~VertexBuffer();

	void Bind();
	void UnBind();
private:
	unsigned int m_id;
};


class IndexBuffer
{
public:
	IndexBuffer(const int* buffer, int count);
	~IndexBuffer();

	const int GetCount() const;

	void Bind();
	void UnBind();

private:
	unsigned int m_id;
	int m_count;
};