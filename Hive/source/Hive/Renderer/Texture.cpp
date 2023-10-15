#include "RLTexture.h"
#include "Texture.h"

namespace Hive
{
    Texture* Texture::Create(float width, float height, const Vector3& color)
    {
        return new RLTexture(width, height, color);
    }

}
