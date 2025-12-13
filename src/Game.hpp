#pragma once

#include <string>

namespace Game
{
    bool Initialize();
    void Shutdown();
    int Run();
    void Quit();
    const char* GetBasePath();
    std::string GetResoucesPath();
};