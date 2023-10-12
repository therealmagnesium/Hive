#pragma once
#include "Types.h"
#include <string>

struct AppConfig
{
    u16 targetFPS;
    s16 width;
    s16 height;
    std::string name;
};

class Application
{
public:
    Application(AppConfig* config);
    virtual ~Application();

    inline void Quit() { m_running = false; }

    virtual void OnStart() = 0;
    virtual void OnProcessInput() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;

    void Run();

private:
    void Init();
    void Shutdown();

private:
    bool m_running = false;
    AppConfig m_config;
};
