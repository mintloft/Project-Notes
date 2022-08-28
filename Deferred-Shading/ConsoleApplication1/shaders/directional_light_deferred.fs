#version 330 core

in vec2 uv;

out vec4 FragColor;

uniform vec3 DirectionalLightDir;
uniform vec3 DirectionalLightColor;

uniform highp vec3 cameraPos;

uniform sampler2D gLastColor;

uniform sampler2D gEmissiveAO;
uniform sampler2D gWorldPosMetallic;
uniform sampler2D gAlbedoSpec;
uniform sampler2D gWorldNormalRoughness;


const float PI = 3.14159265359;
const float InvPI = 0.3183098862;

vec3 GetLastColor(vec2 InUV)
{
	return texture(gLastColor, InUV).rgb;
}

vec3 GetAlbedo(vec2 InUV)
{
	return texture(gAlbedoSpec, InUV).rgb;
}

vec3 GetSpecular(vec2 InUV)
{
	return texture(gAlbedoSpec, InUV).aaa;
}

float GetRoughness(vec2 InUV)
{
	return texture(gWorldNormalRoughness, InUV).a;
}

float GetMetallic(vec2 InUV)
{
	return texture(gWorldPosMetallic, InUV).a;
}

vec3 GetAO(vec2 InUV)
{
	return texture(gEmissiveAO, InUV).aaa;
}

vec3 GetEmissive(vec2 InUV)
{
    return texture(gEmissiveAO, InUV).rgb;
}

highp vec3 GetWorldPosition(vec2 InUV)
{
    return texture(gWorldPosMetallic, InUV).xyz;
}

vec3 GetWorldNormal(vec2 InUV)
{
    return texture(gWorldNormalRoughness, InUV).xyz;
}

float CalcNDF(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float SqNdotH = NdotH*NdotH;
    float nom   = a2;
    float denom = (SqNdotH * a2 - SqNdotH) + 1.0;
	denom = PI * denom * denom;
    return nom / denom;
}

float CalcGeometryOcculicion(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) * 0.125;
    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;
    return nom / denom;
}

float CalcGeometryOcculicionBothDirection(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = CalcGeometryOcculicion(NdotV, roughness);
    float ggx1 = CalcGeometryOcculicion(NdotL, roughness);
    return ggx1 * ggx2;
}

vec3 CalcFreshnel(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}

void main()
{
	vec3 albedo = GetAlbedo(uv);
	float roughness = GetRoughness(uv);
	float metallic = GetMetallic(uv);
	vec3 ao = GetAO(uv);
	vec3 specular = GetSpecular(uv);
    highp vec3 WorldPosition = GetWorldPosition(uv);
    vec3 WorldNormal = GetWorldNormal(uv);

	highp vec3 viewVector = (cameraPos - WorldPosition);
	vec3 viewDir = normalize(viewVector);

	vec3 F0 = vec3(0.04);
	F0 = mix(F0, albedo, metallic);

	vec3 calColor;
	//directional light
	{
		//in comming
		vec3 L = DirectionalLightDir;
		vec3 H = normalize(viewDir + L);
		vec3 LC = DirectionalLightColor;

		float D = CalcNDF(WorldNormal, H, roughness);
		float G = CalcGeometryOcculicionBothDirection(WorldNormal, viewDir, L, roughness);
		vec3 F = CalcFreshnel(clamp(dot(WorldNormal, viewDir), 0.0, 1.0), F0);

		vec3 upPart = D * G * F;
		float downPart = 4*max(dot(WorldNormal,viewDir),0.0)*max(dot(WorldNormal,L),0.0) + 0.01;
		vec3 specularPart = upPart / downPart;

		vec3 kS = F;
		vec3 kD = (vec3(1.0) - kS) * (1.0 - metallic);

		calColor = (kD * albedo * InvPI + specularPart) * LC * max(dot(WorldNormal, L),0.0);
	}

	vec3 finalColor = (calColor);// * specular + EnvLightColor * albedo * ao);
	FragColor = vec4(GetLastColor(uv) + finalColor, 1);// pow(vec4(finalColor/(finalColor + vec3(1)), 1), vec4(1.0/2.2));
}