#pragma once
#include <Hive.h>

class GameScene : public Scene
{
public:
    GameScene(Application* app);

    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update() override;
    void Render() override;

private:
    Application* m_app;
};
