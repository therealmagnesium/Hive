#include "Scene.h"
#include "Entity.h"

namespace Hive
{
    Entity Scene::CreateEntity(const std::string& tag)
    {
        Entity entity(m_registry.create(), this);

        TagComponent& c_tag = entity.AddComponent<TagComponent>();
        TransformComponent& c_transform = entity.AddComponent<TransformComponent>(Vector2Zero(), Vector2Zero(), 0.f);

        c_tag.tag = tag.empty() ? "Entity" : tag;

        return entity;
    }

    Entity* Scene::CreateEntityP(const std::string& tag)
    {
        Entity* entity = new Entity(m_registry.create(), this);

        TagComponent& c_tag = entity->AddComponent<TagComponent>();
        TransformComponent& c_transform = entity->AddComponent<TransformComponent>(Vector2Zero(), Vector2Zero(), 0.f);

        c_tag.tag = tag.empty() ? "Entity" : tag;

        return entity;
    }

}
