#include "GameScene.h"

using namespace Hive;

class Sandbox : public Application
{
public:
    Sandbox(AppConfig* config) : Application(config) {}
    ~Sandbox() { m_sceneStateMachine.Clean(); }

    void OnStart() override
    {
        Scene* gameScene = new GameScene(this);
        u32 gameSceneID = m_sceneStateMachine.Add(gameScene);
        m_sceneStateMachine.SwitchTo(gameSceneID);
    }
    void OnUpdate(float dt) override { m_sceneStateMachine.Update(dt); }
    void OnRender() override { m_sceneStateMachine.Render(); }

private:
    SceneStateMachine m_sceneStateMachine;
};

int main(int argc, char* argv[])
{
    AppConfig config;
    config.targetFPS = 480;
    config.width = 1280;
    config.height = 720;
    config.name = "Sandbox";

    Sandbox* sandbox = new Sandbox(&config);
    sandbox->Run();
    delete sandbox;

    return 0;
}
