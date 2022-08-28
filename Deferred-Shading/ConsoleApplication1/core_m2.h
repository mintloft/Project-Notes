#pragma once
#include <glad/glad.h> 

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <string>
#include <fstream>
#include <functional>
#include <sstream>
#include <iostream>
#include <map> 
#include <queue>
#include <set> 
#include <stb_image.h>
#include <vector>
#include <GLFW/glfw3.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>

template<typename T>
class TInterface : virtual public std::enable_shared_from_this<TInterface<T>>
{
public:
    virtual ~TInterface() = default;
};

class FObject : virtual public std::enable_shared_from_this<FObject>
{
    static long long int GenComponentID();
    long long int objId = -1;
public:
    FObject() : objId(GenComponentID())
    {

    }
    long long int GetObjectId() const { return objId; }
    virtual ~FObject() = default;
};

class FComponentSubobject : public FObject
{

public:
    std::weak_ptr<class FComponent> owner;

    virtual void Init() {}

    virtual void PreTick(float deltaSecond) {};

    virtual void EarlyTick(float deltaSecond) {};

    virtual void Tick(float deltaSecond) {};

    virtual void PostTick(float deltaSecond) {};

    virtual void FinalTick(float deltaSecond) {};
};


class FComponent : public FObject
{
public:
    std::weak_ptr<class FScene> scene;
    std::vector<std::shared_ptr<FComponentSubobject>> subobjects;

    template<typename T>
    std::shared_ptr<T> AddSubobject()
    {
        std::shared_ptr<T> ret = std::make_shared<T>();
        subobjects.push_back(ret);
        ret->owner = std::static_pointer_cast<FComponent>(this->shared_from_this());
        ret->Init();
        return ret;
    }

    template<typename T, typename...Args>
    std::shared_ptr<T> AddSubobjectWithArgs(Args...args)
    {
        std::shared_ptr<T> ret = std::make_shared<T>(std::forward<Args>(args)...);
        subobjects.push_back(ret);
        ret->owner = std::static_pointer_cast<FComponent>(this->shared_from_this());
        ret->Init();
        return ret;
    }

    virtual ~FComponent() override = default;

    virtual void PreTick(float deltaSecond)
    {
        for (auto&& subobject : subobjects)
        {
            subobject->PreTick(deltaSecond);
        }
    };

    virtual void EarlyTick(float deltaSecond)
    {
        for (auto&& subobject : subobjects)
        {
            subobject->EarlyTick(deltaSecond);
        }
    };

    virtual void Tick(float deltaSecond)
    {
        for (auto&& subobject : subobjects)
        {
            subobject->Tick(deltaSecond);
        }
    };

    virtual void PostTick(float deltaSecond)
    {
        for (auto&& subobject : subobjects)
        {
            subobject->PostTick(deltaSecond);
        }
    };

    virtual void FinalTick(float deltaSecond)
    {
        for (auto&& subobject : subobjects)
        {
            subobject->FinalTick(deltaSecond);
        }
    };
};