#include <Hive/Common/Application.h>
#include <Hive/Common/Types.h>

int main(void)
{
    AppConfig config;
    config.targetFPS = 60;
    config.width = 1280;
    config.height = 720;
    config.name = "Sandbox";

    Application* sandbox = new Application(&config);
    sandbox->Run();
    delete sandbox;

    return 0;
}
