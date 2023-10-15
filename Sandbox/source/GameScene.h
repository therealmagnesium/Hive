#pragma once
#include <Hive.h>

using namespace Hive;

class GameScene : public Scene
{
public:
    GameScene(Application* app);

    void OnCreate() override;
    void OnDestroy() override;

    void OnUpdate(float dt) override;
    void OnRender() override;

private:
    Application* m_app;
    Entity* m_entity;
};
