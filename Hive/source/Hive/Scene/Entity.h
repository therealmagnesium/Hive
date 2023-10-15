#pragma once
#include "Components.h"
#include "Scene.h"
#include <entt.hpp>
#include <utility>

namespace Hive
{
    class Entity
    {
    public:
        Entity(entt::entity handle, Scene* scene);
        Entity(const Entity& other) = default;

        inline std::string& GetTag() { return GetComponent<TagComponent>().tag; }

        template <typename T> void RemoveComponent() { m_scene->m_registry.remove<T>(m_handle); }
        template <typename T> bool HasComponent() { return m_scene->m_registry.valid(m_handle); }
        template <typename T> T& GetComponent() { return m_scene->m_registry.get<T>(m_handle); }
        template <typename T, typename... Args> T& AddComponent(Args&&... args)
        {
            return m_scene->m_registry.emplace<T>(m_handle, std::forward<Args>(args)...);
        }

        void LogInfo();

    private:
        entt::entity m_handle{0};
        Scene* m_scene;
    };

}
