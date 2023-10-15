#pragma once
#include <raylib.h>
#include "Renderer/Texture.h"

namespace Hive
{
    struct RLTexture : Texture
    {
        Texture2D texture;
        Color tint;
        Vector2 size;

        RLTexture() : size({0.f, 0.f}) {}
        RLTexture(float width, float height, const Vector3& color);

        void Load(const Vector3& fill);
        void Unload();
        void Draw(float x, float y);
    };
};
