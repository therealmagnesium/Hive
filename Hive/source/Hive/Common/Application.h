#pragma once
#include "Types.h"
#include <string>

struct AppConfig
{
    s16 targetFPS;
    s16 width;
    s16 height;
    std::string name;
};

class Application
{
  public:
    Application(AppConfig* config);
    ~Application();

    void Run();

  private:
    void Init();
    void Shutdown();

  private:
    bool m_running = false;
    AppConfig m_config;
};
