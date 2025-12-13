#pragma once

#include "Controller.hpp"
#include <memory>

namespace UISystem
{
    // Controllers
    extern std::unique_ptr<Controller> MAIN_MENU_CONTROLLER;

    bool Initialize();
    void Shutdown();
    bool ProcessEventsUpdateAndRender();
    Rml::Context& GetContext();
    void SetMenu(Controller* controller);
}