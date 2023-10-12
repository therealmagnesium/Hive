#pragma once
#include <entt.hpp>
#include <string>

class Entity;

class Scene
{
public:
    virtual ~Scene() {}

    virtual void OnCreate() = 0;
    virtual void OnDestroy() = 0;

    virtual void OnActivate() {}
    virtual void OnDeactivate() {}

    virtual void ProcessInput() {}
    virtual void Update() {}
    virtual void Render() {}

    Entity CreateEntity(const std::string& tag);

private:
    friend class Entity;
    entt::registry m_registry;
};
