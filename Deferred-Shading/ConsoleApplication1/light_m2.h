#pragma once
#include "scene_m2.h"

enum class ELightType
{
	LT_Directional,
	LT_Point,
	LT_Env
};

struct FLightRenderBatch
{
	ELightType lightType;
	glm::vec3 color;
	glm::vec3 direction;
	glm::vec3 location;
	float radius;

	std::shared_ptr<FTexture> shadowMap;
	float lightmapDistance;
	int numOfCSM;

	FLightRenderBatch(ELightType inType, glm::vec3 inColor, glm::vec3 inDirection, glm::vec3 inLocation, float inRadius, std::shared_ptr<FTexture> inShadowMap, float inLightmapDistance, int inNumOfCSM) : lightType(inType), color(inColor), direction(inDirection), location(inLocation), radius(inRadius)
		, shadowMap(inShadowMap), lightmapDistance(inLightmapDistance), numOfCSM(inNumOfCSM)
	{

	}
};

class FLightComponent : public FSceneComponent
{
public:


	glm::vec3 lightColor;

	FLightComponent(glm::vec3 inLightColor) : lightColor(inLightColor)
	{
		
	}

	virtual void GetLightRenderBatch(std::vector<FLightRenderBatch>& outElement)
	{
		
	}
};

class FEnvLightComponent : public FLightComponent
{
public:
	static std::shared_ptr<FShader> EnvLightDeferredShader;
	static std::shared_ptr<FPrimitive> EnvLightDeferredGeo;
	FEnvLightComponent(glm::vec3 inLightColor) : FLightComponent(inLightColor)
	{
		
	}
	virtual void GetLightRenderBatch(std::vector<FLightRenderBatch>& outElement) override
	{
		outElement.emplace_back(ELightType::LT_Env, lightColor, GetFowardInWorldSpace(), GetWorldLocation(), 0.0f, nullptr,100.0f,1);
	}
};


class FDirectionalLightComponent : public FLightComponent
{
	int baseShadowMapSize;
	int numOfCSM;
	float lightmapDistance;
	std::shared_ptr<FTexture> shadowMap;
	int GetShadowMapWidth() const
	{
		return baseShadowMapSize * numOfCSM;
	}
public:

	static std::shared_ptr<FShader> DirectionalLightDeferredShader;
	static std::shared_ptr<FPrimitive> DirectionalLightDeferredGeo;

	void SetLightmapDistance(float inDistance)
	{
		lightmapDistance = inDistance;
	}

	void SetShadowMapSize(int inBaseShadowMapSize, int inNumOfCSM = -1)
	{
		const int needNumOfCSM = inNumOfCSM <= 0 ? numOfCSM : inNumOfCSM;
		const int needBaseShadowMapSize = inBaseShadowMapSize <= 0 ? baseShadowMapSize : inBaseShadowMapSize;
		if(needBaseShadowMapSize != baseShadowMapSize || needNumOfCSM != numOfCSM)
		{
			baseShadowMapSize = needBaseShadowMapSize;
			numOfCSM = needNumOfCSM;
			shadowMap = std::make_shared<FTexture>(baseShadowMapSize, GetShadowMapWidth(), ETexturePixelFormat::TPF_D24S8);
		}
	}

	FDirectionalLightComponent(glm::vec3 inLightColor, glm::quat inRotation) : FLightComponent(inLightColor), baseShadowMapSize(1024), numOfCSM(1), lightmapDistance(100.f)
		, shadowMap(std::make_shared<FTexture>(baseShadowMapSize, GetShadowMapWidth(), ETexturePixelFormat::TPF_D24S8))
	{
		SetWorldTransform(glm::mat4_cast(inRotation));
	}

	virtual void GetLightRenderBatch(std::vector<FLightRenderBatch>& outElement) override
	{
		outElement.emplace_back(ELightType::LT_Directional, lightColor, GetFowardInWorldSpace(), GetWorldLocation(), 0.0f, shadowMap, lightmapDistance, numOfCSM);
	}
};

class FPointLightComponent : public FLightComponent
{
public:
	float radius;

	FPointLightComponent(glm::vec3 inLightColor, glm::vec3 inLightLocation, float inRadius) : FLightComponent(inLightColor), radius(inRadius)
	{
		SetWorldLocation(inLightLocation);
	}

	virtual void GetLightRenderBatch(std::vector<FLightRenderBatch>& outElement) override
	{
		outElement.emplace_back(ELightType::LT_Point, lightColor, GetFowardInWorldSpace(), GetWorldLocation(), radius, nullptr, 100.f,1);
	}
};
