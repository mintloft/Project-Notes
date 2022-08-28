#version 330 core

layout (location = 0) out vec4 gEmissiveAO;
layout (location = 1) out highp vec4 gWorldPosMetallic;
layout (location = 2) out vec4 gAlbedoSpec;
layout (location = 3) out vec4 gWorldNormalRoughness;


in vec2 TexCoord;
in highp vec3 WorldPosition;
in vec3 WorldNormal;

// texture samplers
uniform sampler2D Albedo;
uniform sampler2D Specular;
uniform sampler2D Roughness;
uniform sampler2D Metallic;
uniform sampler2D AO;
uniform sampler2D Emissive;



const float PI = 3.14159265359;
const float InvPI = 0.3183098862;

vec3 GetAlbedo(vec2 InUV)
{
	return texture(Albedo, InUV).rgb;
}

vec3 GetSpecular(vec2 InUV)
{
	return texture(Specular, InUV).rrr;
}

float GetRoughness(vec2 InUV)
{
	return texture(Roughness, InUV).r;
}

float GetMetallic(vec2 InUV)
{
	return texture(Metallic, InUV).r;
}

vec3 GetAO(vec2 InUV)
{
	return texture(AO, InUV).rrr;
}

vec3 GetEmissive(vec2 InUV)
{
    return texture(Emissive, InUV).rgb;
}

void main()
{
    gEmissiveAO = vec4(GetEmissive(TexCoord).rgb, GetAO(TexCoord).r);
    gWorldPosMetallic = vec4(WorldPosition.xyz, GetMetallic(TexCoord));
    gAlbedoSpec = vec4(GetAlbedo(TexCoord).rgb, GetSpecular(TexCoord).r);
    gWorldNormalRoughness = vec4(WorldNormal.xyz, GetRoughness(TexCoord));
}