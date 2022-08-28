#version 330 core

#define MAX_BONE_INFLUENCE 4

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec2 TexCoords;
layout (location = 3) in vec3 Tangent;
layout (location = 4) in vec3 Bitangent;
layout (location = 5) in int m_BoneIDs[MAX_BONE_INFLUENCE];
layout (location = 6) in float m_Weights[MAX_BONE_INFLUENCE];

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(Position, 1.0f);
	TexCoord = vec2(TexCoords.x, TexCoords.y);
}