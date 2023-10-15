#pragma once
#include "KeyCodes.h"
#include <raymath.h>
#include <string>

namespace Hive
{
    class Input
    {
    public:
        static float GetMouseX();
        static float GetMouseY();
        static Vector2 GetMousePosition();

        static bool IsMouseButtonClicked(u32 button);
        static bool IsMouseButtonReleased(u32 button);
        static bool IsMouseButtonHeld(u32 button);

        static bool IsKeyTyped(u32 key);
        static bool IsKeyReleased(u32 key);
        static bool IsKeyHeld(u32 key);

        static u32 GetCurrentKey();
        static s8 GetAxis(const std::string& axisName);
    };
};
