#pragma once
#include <Hive.h>

class GameScene : public Scene
{
public:
    GameScene();

    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update() override;
    void Render() override;

private:
};
