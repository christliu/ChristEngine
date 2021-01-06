
class Shader
{
public:
	Shader(const char* path);

	void Bind();
	void UnBind();
private:
	unsigned int m_shaderId;
};