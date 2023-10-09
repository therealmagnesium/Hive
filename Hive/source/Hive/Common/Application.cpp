#include "Application.h"
#include <raylib.h>

Application::Application(AppConfig* config) : m_config(*config) { Init(); }
Application::~Application() { Shutdown(); }

void Application::Init()
{
    InitWindow(m_config.width, m_config.height, m_config.name.c_str());
    SetTargetFPS(m_config.targetFPS);

    m_running = true;

    printf("Initialized Hive application successfully!\n");
}

void Application::Shutdown()
{
    CloseWindow();

    printf("Application shutdown successfully\n");
}

void Application::Run()
{
    OnStart();

    while (m_running)
    {
        m_running = !WindowShouldClose();

        if (IsKeyPressed(KEY_ESCAPE))
            m_running = false;

        OnUpdate();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        OnRender();

        EndDrawing();
    }
}
