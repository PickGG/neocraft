#include "MainMenuController.hpp"
#include "../../Game.hpp"
#include "../UISystem.hpp"
#include "../../Logging.hpp"

MainMenuController::MainMenuController()
    : Controller("views/main_menu.rml")
{
    m_document->AddEventListener(Rml::EventId::Click, this);
}

void MainMenuController::ProcessEvent(Rml::Event &event)
{
    auto id = event.GetTargetElement()->GetId();
    if(id == "start") {
        LOG_DEBUG("start");
    }
    else if (id == "quit") {
        LOG_DEBUG("quit");
        Game::Quit();
    }
}
