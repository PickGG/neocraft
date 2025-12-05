#include "MainMenuController.hpp"
#include "../../Game.hpp"
#include "../UISystem.hpp"

MainMenuController::MainMenuController()
{
    m_view = UISystem::GetContext().LoadDocument(Game::GetResoucesPath() + "views/main_menu.rml");
}

void MainMenuController::OnShow()
{
}

void MainMenuController::OnHide()
{
}

Rml::ElementDocument& MainMenuController::GetDocument()
{
    return *m_view;
}
