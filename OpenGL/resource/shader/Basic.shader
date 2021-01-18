#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 coord;

out vec2 TexCoord;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoord = vec2(coord.x, coord.y);
};

#shader fragment

#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
   FragColor = texture(texture1, TexCoord);
   //FragColor = vec4(TexCoord.x, TexCoord.y, 0.0f, 1.0f);
}