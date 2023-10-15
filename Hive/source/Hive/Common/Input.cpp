#include <raylib.h>
#include "Input.h"

namespace Hive
{
    float Input::GetMouseX() { return ::GetMouseX(); }
    float Input::GetMouseY() { return ::GetMouseY(); }
    Vector2 Input::GetMousePosition() { return ::GetMousePosition(); }

    bool Input::IsMouseButtonClicked(u32 button) { return IsMouseButtonPressed(button); }
    bool Input::IsMouseButtonReleased(u32 button) { return IsMouseButtonReleased(button); }
    bool Input::IsMouseButtonHeld(u32 button) { return IsMouseButtonDown(button); }

    bool Input::IsKeyTyped(u32 key) { return IsKeyPressed(key); }
    bool Input::IsKeyReleased(u32 key) { return ::IsKeyReleased(key); }
    bool Input::IsKeyHeld(u32 key) { return IsKeyDown(key); }

    u32 Input::GetCurrentKey() { return GetKeyPressed(); }

    s8 Input::GetAxis(const std::string& axisName)
    {
        s8 axis = 0;
        if (axisName == "Horizontal")
        {
            if (IsKeyHeld(Key::Right))
                axis = 1;
            else if (IsKeyHeld(Key::Left))
                axis = -1;
        }
        else if (axisName == "Vertical")
        {
            if (IsKeyHeld(Key::Up))
                axis = 1;
            else if (IsKeyHeld(Key::Down))
                axis = -1;
        }
        return axis;
    }
};
