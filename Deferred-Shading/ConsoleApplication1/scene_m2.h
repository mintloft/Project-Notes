#pragma once
#include <glm/glm.hpp>
#include "core_m2.h"


enum class EAttachRule
{
    AR_KeepWorld,
    AR_KeepRelative,
    AR_SnapToTarget,
};

class FSceneComponent : public FComponent
{
    glm::mat4 matrix = glm::mat4(1.0f);
    std::weak_ptr<FSceneComponent> parent;
    std::set<std::shared_ptr<FSceneComponent>> children;

    bool HasChild(const std::shared_ptr<FSceneComponent>& inChild) const
    {
        if (children.find(inChild) != children.end())
        {
            return true;
        }

        for (auto&& child : children)
        {
            if (child->HasChild(inChild))
            {
                return true;
            }
        }

        return false;
    }

public:
    std::weak_ptr<FSceneComponent> GetParent() const
    {
        return parent;
    }

    std::set<std::shared_ptr<FSceneComponent>> GetAllChildren() const
    {
        return children;
    }

    glm::mat4 GetWorldTransform() const
    {
        std::shared_ptr<FSceneComponent> safe_parent = parent.lock();
        if (safe_parent)
        {
            return safe_parent->GetWorldTransform() * matrix;
        }
        return matrix;
    }

    glm::mat4 GetLocalTransform() const
    {
        return matrix;
    }

    void SetLocalTransform(const glm::mat4& inTransform)
    {
        matrix = inTransform;
    }

    void SetWorldTransform(const glm::mat4& inTransform)
    {
        std::shared_ptr<FSceneComponent> safe_parent = parent.lock();
        if (!safe_parent)
        {
            matrix = inTransform;
        }
        else
        {
            auto&& parentTransform = safe_parent->GetWorldTransform();
            matrix = glm::inverse(parentTransform) * inTransform;
        }
    }

    glm::vec3 GetLocalLocation() const
    {
        return (matrix[3]);
    }

    glm::vec3 GetWorldLocation() const
    {
        return GetWorldTransform()[3];
    }

    void SetLocalLocation(const glm::vec3& inLocation)
    {
        matrix[3] = glm::vec4(inLocation, matrix[3][3]);
    }

    void SetWorldLocation(const glm::vec3& inLocation)
    {
        auto worldMatrix = GetWorldTransform();
        worldMatrix[3] = glm::vec4(inLocation, worldMatrix[3][3]);
        SetWorldTransform(worldMatrix);
    }

    glm::vec3 GetFowardInWorldSpace() const
    {
        return normalize((GetWorldTransform() * glm::vec4(0, 0, -1, 0)));
    }

    glm::vec3 GetRightInWorldSpace() const
    {
        return normalize((GetWorldTransform() * glm::vec4(1, 0, 0, 0)));
    }

    glm::vec3 GetUpInWorldSpace() const
    {
        return normalize((GetWorldTransform() * glm::vec4(0, 1, 0, 0)));
    }

    void AttachTo(std::shared_ptr<FSceneComponent> newParent, EAttachRule inRule)
    {
        auto shared_this = std::static_pointer_cast<FSceneComponent>(this->shared_from_this());

        if (newParent == shared_this)
        {
            return;
        }

        std::shared_ptr<FSceneComponent> safe_parent = parent.lock();
        if (safe_parent == newParent)
        {
            return;
        }

        if (HasChild(newParent))
        {
            return;
        }

        glm::mat4 oldWorld = GetWorldTransform();
        if (safe_parent)
        {
            safe_parent->children.erase(shared_this);
        }
        parent = newParent;
        switch (inRule)
        {
        case EAttachRule::AR_KeepRelative:
            break;
        case EAttachRule::AR_SnapToTarget:
            SetLocalTransform(glm::mat4(1.0f));
            break;
        case EAttachRule::AR_KeepWorld:
            SetWorldTransform(oldWorld);
            break;
        }
    }
};


class FScene : public FObject
{
    std::vector<std::shared_ptr<FComponent>> components;

public:
    template<typename T>
    std::shared_ptr<T> CreateComponent()
    {
        auto ret = std::make_shared<T>();
        auto base = std::static_pointer_cast<FComponent>(ret);
        base->scene = std::static_pointer_cast<FScene>(this->shared_from_this());
        components.push_back(base);
        return ret;
    }

    template<typename T, typename...Args>
    std::shared_ptr<T> CreateComponentWithArg(Args...args)
    {
        auto ret = std::make_shared<T>(std::forward<Args>(args)...);
        auto base = std::static_pointer_cast<FComponent>(ret);
        base->scene = std::static_pointer_cast<FScene>(this->shared_from_this());
        components.push_back(base);
        return ret;
    }

    const std::vector<std::shared_ptr<FComponent>>& GetAllComponents() const
    {
        return components;
    }

    void Tick(float deltaSecond)
    {
        auto componentsCopy = components;

        for (auto&& component : componentsCopy)
        {
            component->PreTick(deltaSecond);
        }

        for (auto&& component : componentsCopy)
        {
            component->EarlyTick(deltaSecond);
        }

        for (auto&& component : componentsCopy)
        {
            component->Tick(deltaSecond);
        }

        for (auto&& component : componentsCopy)
        {
            component->PostTick(deltaSecond);
        }

        for (auto&& component : componentsCopy)
        {
            component->FinalTick(deltaSecond);
        }
    }

};

using FSceneRef = std::shared_ptr<FScene>;

