#pragma once
#include "Common/Types.h"
#include "Scene.h"

#include <unordered_map>

class SceneStateMachine
{
public:
    SceneStateMachine();

    void ProcessInput();
    void Update();
    void Render();

    u32 Add(Scene* scene);
    void Remove(u32 id);
    void SwitchTo(u32 id);
    void Clean();

private:
    u32 m_insertedSceneID = 0;
    Scene* m_currentScene;
    std::unordered_map<u32, Scene*> m_scenes;
};
