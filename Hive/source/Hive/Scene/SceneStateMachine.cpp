#include "SceneStateMachine.h"

namespace Hive
{
    SceneStateMachine::SceneStateMachine() {}

    void SceneStateMachine::Update(float dt)
    {
        if (m_currentScene)
            m_currentScene->OnUpdate(dt);
    }

    void SceneStateMachine::Render()
    {
        if (m_currentScene)
            m_currentScene->OnRender();
    }

    u32 SceneStateMachine::Add(Scene* scene)
    {
        auto inserted = m_scenes.insert(std::make_pair(m_insertedSceneID, scene));
        m_insertedSceneID++;
        inserted.first->second->OnCreate();
        return m_insertedSceneID - 1;
    }

    void SceneStateMachine::Remove(u32 id)
    {
        auto it = m_scenes.find(id);
        if (it != m_scenes.end())
            m_currentScene = nullptr;

        it->second->OnDestroy();
        m_scenes.erase(it);
    }

    void SceneStateMachine::SwitchTo(u32 id)
    {
        auto it = m_scenes.find(id);
        if (it != m_scenes.end())
            if (m_currentScene)
                m_currentScene->OnDeactivate();

        m_currentScene = it->second;
        m_currentScene->OnActivate();
    }

    void SceneStateMachine::Clean()
    {
        for (auto scene : m_scenes)
        {
            scene.second->OnDeactivate();
            scene.second->OnDestroy();
            delete scene.second;
        }
    }
}
