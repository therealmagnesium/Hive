#include "Application.h"
#include <raylib.h>

#define FPS_MARGIN 10 // TEMP

namespace Hive
{
    Application::Application(AppConfig* config) : m_config(*config) { Init(); }
    Application::~Application() { Shutdown(); }

    void Application::Init()
    {
        InitWindow(m_config.width, m_config.height, m_config.name.c_str());
        SetTargetFPS(m_config.targetFPS);
        SetExitKey(KEY_NULL);

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

            OnUpdate(GetFrameTime());

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawFPS(FPS_MARGIN, FPS_MARGIN);
            OnRender();

            EndDrawing();
        }
    }
}
