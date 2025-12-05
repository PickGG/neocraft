#pragma once

#include <RmlUi/Core.h>
#include "IController.hpp"
#include <memory>

namespace UISystem
{
    // Controllers
    extern std::unique_ptr<IController> MAIN_MENU_CONTROLLER;

    bool Initialize();
    void Shutdown();
    bool ProcessEventsUpdateAndRender();
    Rml::Context& GetContext();
    void SetMenu(IController* controller);
}