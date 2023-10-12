#include "Entity.h"
#include <stdio.h>

Entity::Entity(entt::entity handle, Scene* scene) : m_handle(handle), m_scene(scene) {}
void Entity::LogInfo()
{
    TagComponent& c_tag = GetComponent<TagComponent>();
    TransformComponent& c_transform = GetComponent<TransformComponent>();

    printf("Tag: %s\n", c_tag.tag.c_str());
    printf("Handle: %d\n", (int)m_handle);
    printf("Position: (%f, %f)\n", c_transform.position.x, c_transform.position.y);
    printf("Velocity: <%f, %f>\n", c_transform.velocity.x, c_transform.velocity.y);
    printf("Angle: %f\n", c_transform.angle);
}
