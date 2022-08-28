#version 330 core

in vec2 uv;

out vec4 FragColor;

uniform vec3 EnvLightColor;
uniform sampler2D gLastColor;
uniform sampler2D gEmissiveAO;
uniform sampler2D gAlbedoSpec;

vec3 GetAlbedo(vec2 InUV)
{
	return texture(gAlbedoSpec, InUV).rgb;
}

vec3 GetAO(vec2 InUV)
{
	return texture(gEmissiveAO, InUV).aaa;
}

vec3 GetEmissive(vec2 InUV)
{
    return texture(gEmissiveAO, InUV).rgb;
}

vec3 GetLastColor(vec2 InUV)
{
	return texture(gLastColor, InUV).rgb;
}

void main()
{
    vec3 albedo = GetAlbedo(uv);
    vec3 ao = GetAO(uv);

    FragColor = vec4(GetLastColor(uv) + EnvLightColor * albedo * ao + GetEmissive(uv),1);
    // float gray = dot(texture(sceneColor, uv).rgb, vec3(0.3,0.59,0.11));
    // FragColor = vec4(gray,gray,gray,1);/*  */
    // FragColor = pow(vec4(texture(sceneColor, uv).rgb, 1.0), vec4(1.0/2.2));
}
