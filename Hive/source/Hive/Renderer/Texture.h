#pragma once
#include <raymath.h>

namespace Hive
{
    struct Texture
    {
        static Texture* Create(float width, float height, const Vector3& color);

        virtual void Load(const Vector3& fill) = 0;
        virtual void Unload() = 0;
        virtual void Draw(float x, float y) = 0;
    };
};
