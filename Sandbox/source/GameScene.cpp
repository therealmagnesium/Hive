#include "GameScene.h"

GameScene::GameScene(Application* app) : m_app(app) {}

void GameScene::OnCreate()
{
    Entity entity = CreateEntity("main");
    Entity other = CreateEntity("other");

    entity.LogInfo();
    other.LogInfo();
}

void GameScene::OnDestroy() {}

void GameScene::ProcessInput() {}

void GameScene::Update() {}

void GameScene::Render() {}
