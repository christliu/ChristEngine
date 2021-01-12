#pragma once

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer
{
public:
	Renderer();

	void Render(VertexArray& vao, IndexBuffer&, Shader& shader);
};