#pragma once

#include <string>

namespace Game
{
    bool Initialize();
    void Shutdown();
    int Run();
    const char* GetBasePath();
    std::string GetResoucesPath();
};