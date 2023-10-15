#pragma once
#include <raymath.h>

namespace Hive
{
    class Renderer
    {
    public:
        static Vector4 clearColor;

    public:
        static void BeginScene();
        static void EndScene();
    };
}
