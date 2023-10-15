#include "GameScene.h"

static float walkSpeed = 850.f;
static float sprintSpeed = 1300.f;

GameScene::GameScene(Application* app) : m_app(app) {}

void GameScene::OnCreate()
{
    m_entity = CreateEntityP("square");

    TransformComponent& c_transform = m_entity->GetComponent<TransformComponent>();
    SpriteComponent& c_sprite = m_entity->AddComponent<SpriteComponent>(100.f, 100.f, (Vector3){0xFF, 0xFF, 0xFF});

    c_transform.position = {100.f, 100.f};
    c_transform.velocity = {0.f, 0.f};
    c_sprite.color = {0x00, 0xCC, 0xEE};
    c_sprite.texture->Load(c_sprite.color);

    m_entity->LogInfo();
}

void GameScene::OnDestroy()
{
    SpriteComponent& c_sprite = m_entity->GetComponent<SpriteComponent>();
    c_sprite.texture->Unload();
}

void GameScene::OnUpdate(float dt)
{
    if (Input::IsKeyTyped(Key::Escape))
        m_app->Quit();

    TransformComponent& c_transform = m_entity->GetComponent<TransformComponent>();

    s8 direction = Input::GetAxis("Horizontal");

    if (Input::IsKeyHeld(Key::LeftShift))
        c_transform.velocity.x = direction * sprintSpeed;
    else
        c_transform.velocity.x = direction * walkSpeed;

    bool leftSideCheck = (c_transform.position.x <= 0.f && c_transform.velocity.x <= 0.f);
    bool rightSideCheck = (c_transform.position.x >= 1280.f - 100.f && c_transform.velocity.x >= 0.f);

    if (leftSideCheck || rightSideCheck)
        c_transform.velocity.x = 0.f;

    c_transform.position.x += c_transform.velocity.x * dt;
}

void GameScene::OnRender()
{
    TransformComponent& c_transform = m_entity->GetComponent<TransformComponent>();
    SpriteComponent& c_sprite = m_entity->GetComponent<SpriteComponent>();
    c_sprite.texture->Draw(c_transform.position.x, c_transform.position.y);
}
