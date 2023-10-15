#pragma once
#include <entt.hpp>
#include <string>

namespace Hive
{
    class Entity;

    class Scene
    {
    public:
        virtual ~Scene() {}

        virtual void OnCreate() = 0;
        virtual void OnDestroy() = 0;

        virtual void OnActivate() {}
        virtual void OnDeactivate() {}

        virtual void OnUpdate(float dt) {}
        virtual void OnRender() {}

        Entity CreateEntity(const std::string& tag);
        Entity* CreateEntityP(const std::string& tag);

    private:
        friend class Entity;
        entt::registry m_registry;
    };
}
