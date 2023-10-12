#include "GameScene.h"

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
    void OnProcessInput() override { m_sceneStateMachine.ProcessInput(); }
    void OnUpdate() override { m_sceneStateMachine.Update(); }
    void OnRender() override { m_sceneStateMachine.Render(); }

private:
    SceneStateMachine m_sceneStateMachine;
};

int main(int argc, char* argv[])
{
    AppConfig config;
    config.targetFPS = 60;
    config.width = 1280;
    config.height = 720;
    config.name = "Sandbox";

    Sandbox* sandbox = new Sandbox(&config);
    sandbox->Run();
    delete sandbox;

    return 0;
}
