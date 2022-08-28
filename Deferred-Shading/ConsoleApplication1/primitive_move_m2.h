#pragma once
#include "input_m2.h"
#include "scene_m2.h"

enum class ECameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    Up,
    Down,
};

// Default camera values
const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


class FSimpleImputMoveComponentSubobject : public FComponentSubobject
{
public:
    std::weak_ptr<FSceneComponent> sceneCompOwner;

    float MovementSpeed = SPEED;
    int priority;
    float Yaw;
    float Pitch;
    FSimpleImputMoveComponentSubobject(int inPriority, float yaw = YAW, float pitch = PITCH) :priority(inPriority), Yaw(yaw), Pitch(pitch)
    {

    }

    virtual void Init() override
    {
        sceneCompOwner = std::dynamic_pointer_cast<FSceneComponent>(owner.lock());
        FInputReceiver::FObjectInputKey key;
        key.priority = priority;
        key.objId = sceneCompOwner.lock()->GetObjectId();

        auto&& inputHandle = FInputReceiver::GetInputReceiver().keyHandles[key];
        std::weak_ptr<FSimpleImputMoveComponentSubobject> weakThis = std::static_pointer_cast<FSimpleImputMoveComponentSubobject>(this->shared_from_this());
        inputHandle.mouseCallback = [weakThis](double prePosX, double prePosY, double curPosX, double curPosY)->void
        {
            std::shared_ptr<FSimpleImputMoveComponentSubobject> safeThis = weakThis.lock();
            if (safeThis)
            {
                float xoffset = static_cast<float>(curPosX - prePosX);
                float yoffset = static_cast<float>(curPosY - prePosY);
                xoffset *= 0.1f;
                yoffset *= 0.1f;

                safeThis->Yaw -= xoffset;
                safeThis->Pitch -= yoffset;


                if (safeThis->Pitch > 89.0f)
                    safeThis->Pitch = 89.0f;
                if (safeThis->Pitch < -89.0f)
                    safeThis->Pitch = -89.0f;


                safeThis->updateSceneComponentVectors();
            }
        };


        inputHandle.repeatCallback = [weakThis](int key)->void
        {
            std::shared_ptr<FSimpleImputMoveComponentSubobject> safeThis = weakThis.lock();
            if (safeThis)
            {
                std::shared_ptr<FSceneComponent> cameraOwner = safeThis->sceneCompOwner.lock();
                ECameraMovement direction;


                if (key == GLFW_KEY_W)
                    direction = ECameraMovement::FORWARD;
                else if (key == GLFW_KEY_S)
                    direction = ECameraMovement::BACKWARD;
                else if (key == GLFW_KEY_A)
                    direction = ECameraMovement::LEFT;
                else if (key == GLFW_KEY_D)
                    direction = ECameraMovement::RIGHT;
                else if (key == GLFW_KEY_E)
                    direction = ECameraMovement::Up;
                else if (key == GLFW_KEY_Q)
                    direction = ECameraMovement::Down;
                else
                    return;

                float velocity = safeThis->MovementSpeed * FInputReceiver::GetInputReceiver().deltaTime;
                if (direction == ECameraMovement::FORWARD)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() + cameraOwner->GetFowardInWorldSpace() * velocity);

                if (direction == ECameraMovement::BACKWARD)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() - cameraOwner->GetFowardInWorldSpace() * velocity);

                if (direction == ECameraMovement::LEFT)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() - cameraOwner->GetRightInWorldSpace() * velocity);

                if (direction == ECameraMovement::RIGHT)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() + cameraOwner->GetRightInWorldSpace() * velocity);

                if (direction == ECameraMovement::Up)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() + cameraOwner->GetUpInWorldSpace() * velocity);

                if (direction == ECameraMovement::Down)
                    cameraOwner->SetWorldLocation(cameraOwner->GetWorldLocation() - cameraOwner->GetUpInWorldSpace() * velocity);
            }
        };


    }

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateSceneComponentVectors()
    {
        std::shared_ptr<FSceneComponent> safeOwner = sceneCompOwner.lock();
        // calculate the new Front vector
        auto transform = glm::translate(glm::mat4(1.0f), safeOwner->GetWorldLocation()) *
            glm::rotate(glm::mat4(1.0f), glm::radians(Yaw), glm::vec3(0, 1, 0)) *
            glm::rotate(glm::mat4(1.0f), glm::radians(Pitch), glm::vec3(1, 0, 0));

        safeOwner->SetWorldTransform(transform);
    }

};