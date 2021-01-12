#include "Renderer.h"
#include "VertexArray.h"
#include "Shader.h"

Renderer::Renderer()
{
}

void Renderer::Render(VertexArray& vao, IndexBuffer& ib, Shader& shader)
{
	vao.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
}
