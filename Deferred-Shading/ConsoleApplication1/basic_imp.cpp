#include "shader_m2.h"
#include "primitive_m2.h"
#include "input_m2.h"
#include "primitive_move_m2.h"
#include "light_m2.h"

std::shared_ptr<FShader> FDirectionalLightComponent::DirectionalLightDeferredShader;
std::shared_ptr<FPrimitive> FDirectionalLightComponent::DirectionalLightDeferredGeo;

std::shared_ptr<FShader> FEnvLightComponent::EnvLightDeferredShader;
std::shared_ptr<FPrimitive> FEnvLightComponent::EnvLightDeferredGeo;

std::shared_ptr<FShader> FCameraComponent::FinalShader;
std::shared_ptr<FPrimitive> FCameraComponent::FinalPrimitive;

FInputReceiver& FInputReceiver::GetInputReceiver()
{
    static FInputReceiver innerReceiver;
    return innerReceiver;
}

long long FObject::GenComponentID()
{
    static long long int curId = 0;
    return curId++;
}

FCameraComponent::FDeferredDrawer& FCameraComponent::GetDeferredCmds()
{
    static FDeferredDrawer innerDrawer;
    return innerDrawer;
}

void FCameraComponent::AdjustGBuffer()
{
    if(bDeferredPipeline)
    {
        FFrameBufferRef useFrameBuffer = frameBufferRef ? frameBufferRef : FFrameBuffer::GetDefaultFrameBuffer();
        bool bViewportSet = false;
        glm::vec2 viewportSize;
        if (!useFrameBuffer->IsEmpty())
        {
            if (useFrameBuffer->Color[0]->IsValid())
            {
                viewportSize = useFrameBuffer->Color[0]->GetSize();
                bViewportSet = true;
            }
            else if (useFrameBuffer->Depth->IsValid())
            {
                viewportSize = useFrameBuffer->Depth->GetSize();
                bViewportSet = true;
            }
        }
        if (!bViewportSet)
        {
            int x, y;
            glfwGetFramebufferSize(glfwGetCurrentContext(), &x, &y);
            viewportSize.x = x;
            viewportSize.y = y;
        }
        if(!gBufferRef || gBufferRef->Color[0]->GetSize() != viewportSize)
        {
            gBufferRef = std::make_shared<FFrameBuffer>(static_cast<int>(viewportSize.x), static_cast<int>(viewportSize.y), 4, EFrameBufferColorFormat::FCF_RGBA16F);
            gFlipBufferRefs[0] = std::make_shared<FFrameBuffer>(static_cast<int>(viewportSize.x), static_cast<int>(viewportSize.y), 1, EFrameBufferColorFormat::FCF_RGBA);
            gFlipBufferRefs[1] = std::make_shared<FFrameBuffer>(static_cast<int>(viewportSize.x), static_cast<int>(viewportSize.y), 1, EFrameBufferColorFormat::FCF_RGBA);
        }
    }
    else
    {
        gBufferRef = nullptr;
    }
}

FCameraComponent::FCameraComponent(glm::vec3 position) :frameBufferRef(FFrameBuffer::GetDefaultFrameBuffer()), Zoom(ZOOM)
{
    SetWorldLocation(position);
}

void FCameraComponent::DrawDeferred() const
{
    auto&& drawer = GetDeferredCmds();
    if(drawer.registeredCamera.find(this) == drawer.registeredCamera.end())
    {
        drawer.registeredCamera.emplace(this);

        std::weak_ptr<const FCameraComponent> weakThis = std::static_pointer_cast<const FCameraComponent>(this->shared_from_this());

        if (!frameBufferRef || frameBufferRef->IsEmpty())
        {
            drawer.deferredCommands.emplace([weakThis]()->void
                {
                    auto safeCamera = weakThis.lock();
                    if (safeCamera)
                    {
                        safeCamera->Draw();
                    }
                });
        }
        else
        {
            drawer.preDeferredCommands.emplace([weakThis]()->void
                {
                    auto safeCamera = weakThis.lock();
                    if (safeCamera)
                    {
                        safeCamera->Draw();
                    }
                });
        }
    	
    }
}

void FCameraComponent::Draw() const
{
    std::vector<FRenderBatch> renderBatches;
    std::vector<FLightRenderBatch> lights;

    auto safe_scene = scene.lock();
    auto&& allComponents = safe_scene->GetAllComponents();
    for (auto&& component : allComponents)
    {
        auto primitiveComponent = std::dynamic_pointer_cast<FPrimitiveComponent>(component);
        if (primitiveComponent)
        {
            if(renderOnlyPrimitives.size() == 0)
            {
                if (ignorePrimitives.find(primitiveComponent) == ignorePrimitives.end())
                {
                    primitiveComponent->GenerateRenderBatch(renderBatches);
                }
            }
            else
            {
                if (renderOnlyPrimitives.find(primitiveComponent) != renderOnlyPrimitives.end())
                {
                    primitiveComponent->GenerateRenderBatch(renderBatches);
                }
            }
        }
        else
        {
            auto lightComponent = std::dynamic_pointer_cast<FLightComponent>(component);
            if(lightComponent)
            {
                lightComponent->GetLightRenderBatch(lights);
            }
        }
    }
    FFrameBufferRef useFrameBuffer = frameBufferRef ? frameBufferRef : FFrameBuffer::GetDefaultFrameBuffer();

    bool bViewportSet = false;
    glm::vec2 viewportSize;
    if(!useFrameBuffer->IsEmpty())
    {
        if(useFrameBuffer->Color[0]->IsValid())
        {
            viewportSize = useFrameBuffer->Color[0]->GetSize();
            bViewportSet = true;
        }
        else if(useFrameBuffer->Depth->IsValid())
        {
            viewportSize = useFrameBuffer->Depth->GetSize();
            bViewportSet = true;
        }
    }
    if(!bViewportSet)
    {
        int x, y;
        glfwGetFramebufferSize(glfwGetCurrentContext(), &x, &y);
        viewportSize.x = x;
        viewportSize.y = y;
    }

    glm::vec4 clearColor = useFrameBuffer->clearColor;

    if(bDeferredPipeline)
    {
        const_cast<FCameraComponent*>(this)->AdjustGBuffer();

        gBufferRef->Use();
        glViewport(0, 0, static_cast<GLsizei>(viewportSize.x), static_cast<GLsizei>(viewportSize.y));
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    	//draw shadow maps
#if 0
        for (auto&& light : lights)
        {
            switch (light.lightType)
            {
            case ELightType::LT_Directional:
                if(light.shadowMap)
                {
                    float zoomInRadius = glm::radians(Zoom);
                    float tanHalfZoom = glm::tan(zoomInRadius / 2.0f);
                    auto bufferSize = gBufferRef->Color[0]->GetSize();
                    float aspectRatio = bufferSize.x / bufferSize.y;
                    for(int CSMIndex = 0; CSMIndex < light.numOfCSM; ++CSMIndex)
                    {
                        float CSMInnerFarPlane = ((CSMIndex + 1) / (float)light.numOfCSM) * light.lightmapDistance;
                        float CSMInnerNearPlane = ((CSMIndex) / (float)light.numOfCSM) * light.lightmapDistance;

                        float lhalfHight = CSMInnerFarPlane * tanHalfZoom;
                        float lhalfWidth = lhalfHight * aspectRatio;
                        float lHalfLength = (CSMInnerFarPlane - CSMInnerNearPlane) / 2;
                        float CSMRadius = glm::sqrt(lhalfHight * lhalfHight + lhalfWidth * lhalfWidth + lHalfLength * lHalfLength);


                        glm::vec3 shadowCasterPos = GetWorldLocation() + GetFowardInWorldSpace() * (CSMInnerNearPlane + CSMInnerFarPlane) * 0.5f - light.direction * 1000.0f;
                        glm::vec3 shadowCasterUp = glm::vec3(0, 1, 0);
                        if(glm::abs(glm::abs(dot(light.direction, shadowCasterUp))-1.0f) < 0.05f)
                        {
                            shadowCasterUp = glm::vec3(0, 0, -1);
                        }

                        glm::mat4 casterView = glm::lookAt(shadowCasterPos, shadowCasterPos + light.direction, shadowCasterUp);
                        glm::mat4 proj = glm::ortho(-CSMRadius, CSMRadius, -CSMRadius, CSMRadius);

                        for (auto&& primitve : renderBatches)
                        {
                            primitve.Draw_InputVP(casterView, proj, shadowCasterPos);
                        }
                    }

                }
                break;
            case ELightType::LT_Point:

                break;
            case ELightType::LT_Env:
                break;
            }
        }
#endif
        //draw g-buffer
        for(auto&& renderBatch : renderBatches)
        {
            renderBatch.Draw(std::static_pointer_cast<FCameraComponent>(((FCameraComponent*)this)->shared_from_this()));
        }
        glUseProgram(0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        gFlipBufferRefs[0]->Use();
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        gFlipBufferRefs[1]->Use();
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

    	glDisable(GL_DEPTH_TEST);
        int curFlipBufferIndex = 0;
        //draw lights;
        for (auto&& light : lights)
        {
            switch (light.lightType)
            {
            case ELightType::LT_Directional:
	            {
                if (!FDirectionalLightComponent::DirectionalLightDeferredShader)
                {
                    FDirectionalLightComponent::DirectionalLightDeferredShader = std::make_shared<FShader>("./shaders/directional_light_deferred.vs", "./shaders/directional_light_deferred.fs");
                    
                }
                if (!FDirectionalLightComponent::DirectionalLightDeferredGeo)
                {
                    FDirectionalLightComponent::DirectionalLightDeferredGeo = std::make_shared<FPrimitive>();

                    float geoDatas[] = {
                        -1.0f, 1.0f, -0.5f,
                        -1.0f, -1.0f,-0.5f,
                        1.0f, -1.0f,-0.5f,
                        1.0f, 1.0f, -0.5f
                    };

                    std::vector<char> vertex;
                    vertex.resize(sizeof(geoDatas));
                    memcpy(vertex.data(), geoDatas, vertex.size());

                    std::vector<unsigned int> index = {
                        0, 1, 2, 0, 2, 3
                    };

                    FPrimitiveVertexDesc desc;
                    desc.structSize = 3 * sizeof(float);
                    FPrimitiveVertexPropDesc prop(0, nullptr, GL_FLOAT, 3);
                    desc.props.push_back(prop);

                    FDirectionalLightComponent::DirectionalLightDeferredGeo->SetData(vertex, index, desc);
                }
                FDirectionalLightComponent::DirectionalLightDeferredShader->use();
                FDirectionalLightComponent::DirectionalLightDeferredGeo->use();

                FDirectionalLightComponent::DirectionalLightDeferredShader->SetTexture("gWorldPosMetallic", gBufferRef->Color[1]);
                FDirectionalLightComponent::DirectionalLightDeferredShader->SetTexture("gAlbedoSpec", gBufferRef->Color[2]);
                FDirectionalLightComponent::DirectionalLightDeferredShader->SetTexture("gWorldNormalRoughness", gBufferRef->Color[3]);
                FDirectionalLightComponent::DirectionalLightDeferredShader->setVec3("DirectionalLightDir", -light.direction);
                FDirectionalLightComponent::DirectionalLightDeferredShader->setVec3("DirectionalLightColor", light.color);
                FDirectionalLightComponent::DirectionalLightDeferredShader->setVec3("cameraPos", GetWorldLocation());

                int lastFlipBuffer = (curFlipBufferIndex + 1) % 2;
                gFlipBufferRefs[curFlipBufferIndex]->Use();
                glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
                FDirectionalLightComponent::DirectionalLightDeferredShader->SetTexture("gLastColor", gFlipBufferRefs[lastFlipBuffer]->Color[0]);

                glDrawElements(GL_TRIANGLES, FDirectionalLightComponent::DirectionalLightDeferredGeo->GetNumOfIndices(), GL_UNSIGNED_INT, nullptr);

                glBindVertexArray(0);
                glUseProgram(0);
                glBindFramebuffer(GL_FRAMEBUFFER, 0);

                curFlipBufferIndex = lastFlipBuffer;
                break;
	            }
            case ELightType::LT_Point:
                
                break;
            case ELightType::LT_Env:
                if(!FEnvLightComponent::EnvLightDeferredGeo)
                {
                    FEnvLightComponent::EnvLightDeferredGeo = std::make_shared<FPrimitive>();

                    float geoDatas[] = {
                        -1.0f, 1.0f, -0.5f,
                        -1.0f, -1.0f,-0.5f,
                        1.0f, -1.0f,-0.5f,
                        1.0f, 1.0f, -0.5f
                    };

                    std::vector<char> vertex;
                    vertex.resize(sizeof(geoDatas));
                    memcpy(vertex.data(), geoDatas, vertex.size());

                    std::vector<unsigned int> index = {
                        0, 1, 2, 0, 2, 3
                    };

                    FPrimitiveVertexDesc desc;
                    desc.structSize = 3 * sizeof(float);
                    FPrimitiveVertexPropDesc prop(0, nullptr, GL_FLOAT, 3);
                    desc.props.push_back(prop);

                    FEnvLightComponent::EnvLightDeferredGeo->SetData(vertex, index, desc);
                }
                if(!FEnvLightComponent::EnvLightDeferredShader)
                {
                    FEnvLightComponent::EnvLightDeferredShader = std::make_shared<FShader>("./shaders/env_light_deferred.vs", "./shaders/env_light_deferred.fs");
                }
            {

                    int lastFlipBuffer = (curFlipBufferIndex + 1) % 2;
                    gFlipBufferRefs[curFlipBufferIndex]->Use();
                    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
                    FEnvLightComponent::EnvLightDeferredShader->SetTexture("gEmissiveAO", gBufferRef->Color[0]);
                    FEnvLightComponent::EnvLightDeferredShader->SetTexture("gAlbedoSpec", gBufferRef->Color[2]);
            		FEnvLightComponent::EnvLightDeferredShader->SetTexture("gLastColor", gFlipBufferRefs[lastFlipBuffer]->Color[0]);
                    FEnvLightComponent::EnvLightDeferredShader->setVec3("EnvLightColor", light.color);
                    FEnvLightComponent::EnvLightDeferredShader->use();
            		FEnvLightComponent::EnvLightDeferredGeo->use();

                    glDrawElements(GL_TRIANGLES, FEnvLightComponent::EnvLightDeferredGeo->GetNumOfIndices(), GL_UNSIGNED_INT, nullptr);

                    glBindVertexArray(0);
                    glUseProgram(0);
                    glBindFramebuffer(GL_FRAMEBUFFER, 0);

                    curFlipBufferIndex = lastFlipBuffer;

            }

                break;

            }
        }

        useFrameBuffer->Use();
        
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        if(!FinalShader)
        {
            FinalShader = std::make_shared<FShader>("./shaders/final_shader.vs", "./shaders/final_shader.fs");
        }
        if(!FinalPrimitive)
        {
            FinalPrimitive = std::make_shared<FPrimitive>();

            float geoDatas[] = {
                -1.0f, 1.0f, -0.5f,
                -1.0f, -1.0f,-0.5f,
                1.0f, -1.0f,-0.5f,
                1.0f, 1.0f, -0.5f
            };

            std::vector<char> vertex;
            vertex.resize(sizeof(geoDatas));
            memcpy(vertex.data(), geoDatas, vertex.size());

            std::vector<unsigned int> index = {
                0, 1, 2, 0, 2, 3
            };

            FPrimitiveVertexDesc desc;
            desc.structSize = 3 * sizeof(float);
            FPrimitiveVertexPropDesc prop(0, nullptr, GL_FLOAT, 3);
            desc.props.push_back(prop);

            FinalPrimitive->SetData(vertex, index, desc);
        }

        FinalShader->use();
        FinalPrimitive->use();

        FinalShader->SetTexture("sceneColor", gFlipBufferRefs[(curFlipBufferIndex + 1) % 2]->Color[0]);

        glDrawElements(GL_TRIANGLES, FinalPrimitive->GetNumOfIndices(), GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
    	glUseProgram(0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        useFrameBuffer->Use();
        glViewport(0, 0, static_cast<GLsizei>(viewportSize.x), static_cast<GLsizei>(viewportSize.y));
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        for (auto&& renderBatch : renderBatches)
        {
            renderBatch.Shader->setVec3("DirectionalLightDir", glm::vec3(1, 0, 0));
            renderBatch.Shader->setVec3("DirectionalLightColor", glm::vec3(0, 0, 0));

            for (int pointLightId = 0; pointLightId < 4; ++pointLightId)
            {
                renderBatch.Shader->setVec4(std::string("PointLightLocationAndRadius[") + std::to_string(pointLightId) + "]", glm::vec4(0, 0, 0, 0));
                renderBatch.Shader->setVec3(std::string("PointLightColor[") + std::to_string(pointLightId) + "]", glm::vec3(0, 0, 0));
            }

            renderBatch.Shader->setVec3("EnvLightColor", glm::vec3(0, 0, 0));

            int pointLightNum = 0;
            for (auto&& light : lights)
            {
                switch (light.lightType)
                {
                case ELightType::LT_Directional:
                    renderBatch.Shader->setVec3("DirectionalLightDir", -light.direction);
                    renderBatch.Shader->setVec3("DirectionalLightColor", light.color);
                    break;
                case ELightType::LT_Point:
                    if (pointLightNum < 4)
                    {
                        renderBatch.Shader->setVec4(std::string("PointLightLocationAndRadius[") + std::to_string(pointLightNum) + "]", glm::vec4(light.location, light.radius));
                        renderBatch.Shader->setVec3(std::string("PointLightColor[") + std::to_string(pointLightNum) + "]", light.color);
                        ++pointLightNum;
                    }
                    break;
                case ELightType::LT_Env:
                    renderBatch.Shader->setVec3("EnvLightColor", light.color);
                    break;

                }
            }
            renderBatch.Draw(std::static_pointer_cast<FCameraComponent>(((FCameraComponent*)this)->shared_from_this()));
        }
        glUseProgram(0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}

std::shared_ptr<FTexture>& FTexture::GetBlack()
{
    static FTextureRef inner = std::make_shared<FTexture>(glm::vec3(0, 0, 0));
    return inner;
}

std::shared_ptr<FTexture>& FTexture::GetWhite()
{
    static FTextureRef inner = std::make_shared<FTexture>(glm::vec3(1, 1, 1));
    return inner;
}

const std::shared_ptr<FFrameBuffer>& FFrameBuffer::GetDefaultFrameBuffer()
{
    static std::shared_ptr<FFrameBuffer> inner = std::make_shared<FFrameBuffer>();
    return inner;
}


