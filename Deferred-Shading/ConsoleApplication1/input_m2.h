#pragma once
#include "core_m2.h"

class FInputReceiver
{
public:
    struct FInputKeyHandle
    {
        int priority = -1;
        std::function<void(int)> pressCallback;
        std::function<void(int)> releaseCallback;
        std::function<void(int)> repeatCallback;
        std::function<void(double, double, double, double)> mouseCallback;
    };

    long long int frameIndex = 0;
    float deltaTime = 0.0f;
    static FInputReceiver& GetInputReceiver();

    class FObjectInputKey
    {
    public:
        long long int objId = -1;
        long long int priority = -1;

        bool operator<(const FObjectInputKey& other) const
        {
            if (priority != other.priority)
            {
                return priority < other.priority;
            }
            return objId < other.objId;
        }
    };

    std::map<int, std::tuple<bool, bool>> keyStatus;
    double mousePos[4];
    std::map<FObjectInputKey, FInputKeyHandle> keyHandles;

    void Execute()
    {
        bool bExecuteMouse = (mousePos[0] != mousePos[2] || mousePos[1] != mousePos[3]);

        for (auto&& keyHandle : keyHandles)
        {
            for (auto&& keyStatu : keyStatus)
            {
                if (std::get<0>(keyStatu.second) != std::get<1>(keyStatu.second))
                {
                    if (std::get<0>(keyStatu.second))
                    {
                        if (keyHandle.second.releaseCallback)
                        {
                            keyHandle.second.releaseCallback(keyStatu.first);
                        }
                    }
                    else
                    {
                        if (keyHandle.second.pressCallback)
                        {
                            keyHandle.second.pressCallback(keyStatu.first);
                        }
                    }
                }
                else
                {
                    if (std::get<0>(keyStatu.second))
                    {
                        if (keyHandle.second.repeatCallback)
                        {
                            keyHandle.second.repeatCallback(keyStatu.first);
                        }
                    }
                }

            }
            if (bExecuteMouse && keyHandle.second.mouseCallback)
            {
                keyHandle.second.mouseCallback(mousePos[0], mousePos[1], mousePos[2], mousePos[3]);
            }
        }
    }

    void FinalExecute()
    {
        mousePos[0] = mousePos[2];
        mousePos[1] = mousePos[3];
        for (auto&& keyStatu : keyStatus)
        {
            std::get<0>(keyStatu.second) = std::get<1>(keyStatu.second);
        }
    }
};
