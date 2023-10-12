#pragma once

#include <raymath.h>
#include <string>

struct TagComponent
{
    std::string tag;

    TagComponent() = default;
    TagComponent(const TagComponent&) = default;
    TagComponent(const std::string& tagIn) : tag(tagIn) {}
};

struct TransformComponent
{
    Vector2 position = {0.f, 0.f};
    Vector2 velocity = {0.f, 0.f};
    float angle = 0.f;

    TransformComponent() = default;
    TransformComponent(const TransformComponent&) = default;
    TransformComponent(Vector2 positionIn, Vector2 velocityIn, float angleIn)
        : position(positionIn), velocity(velocityIn), angle(angleIn)
    {
    }
};
