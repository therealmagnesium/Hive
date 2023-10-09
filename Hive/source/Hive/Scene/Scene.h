#pragma once

class Scene
{
public:
    virtual ~Scene() {}

    virtual void OnCreate() = 0;
    virtual void OnDestroy() = 0;

    virtual void OnActivate() {}
    virtual void OnDeactivate() {}

    virtual void ProcessInput() {}
    virtual void Update() {}
    virtual void Render() {}
};
