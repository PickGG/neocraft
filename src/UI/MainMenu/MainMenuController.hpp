#pragma once

#include "../Controller.hpp"
#include <RmlUi/Core/EventListener.h>
#include <RmlUi/Core/Event.h>

class MainMenuController : public Controller, public Rml::EventListener
{
public:
    MainMenuController();
    void ProcessEvent(Rml::Event& event);
};