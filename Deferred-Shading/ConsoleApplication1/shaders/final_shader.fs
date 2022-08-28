#version 330 core

in vec2 uv;

out vec4 FragColor;

uniform sampler2D sceneColor;

void main()
{
    // float gray = dot(texture(sceneColor, uv).rgb, vec3(0.3,0.59,0.11));
    // FragColor = vec4(gray,gray,gray,1);/*  */
    FragColor = pow(vec4(texture(sceneColor, uv).rgb, 1.0), vec4(1.0/2.2));
}
