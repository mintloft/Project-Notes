#version 330 core

layout (location = 0) in vec3 Position;

out vec2 uv;

void main()
{
    gl_Position = vec4(Position, 1.0f);
    uv = Position.xy * vec2(0.5f,0.5f) + vec2(0.5f,0.5f);
}