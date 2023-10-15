#include "RLTexture.h"
#include "Common/Types.h"

namespace Hive
{
    RLTexture::RLTexture(float width, float height, const Vector3& color)
        : size({width, height}), tint({(u8)color.x, (u8)color.y, (u8)color.z, 0xFF})
    {
    }

    void RLTexture::Load(const Vector3& fill)
    {
        Color fillColor = {(u8)fill.x, (u8)fill.y, (u8)fill.z, 0xFF};
        Image temp = GenImageColor(size.x, size.y, fillColor);
        texture = LoadTextureFromImage(temp);
        UnloadImage(temp);
    }

    void RLTexture::Unload() { UnloadTexture(texture); }

    void RLTexture::Draw(float x, float y) { DrawTexture(texture, x, y, tint); }

}
