#include "Controller.hpp"
#include "UISystem.hpp"
#include "../Game.hpp"

Controller::Controller(const char* documentPath)
{
    m_document = UISystem::GetContext().LoadDocument(Game::GetResoucesPath() + documentPath);
}

Controller::~Controller()
{
}

void Controller::Show()
{
    m_document->Show();
}

void Controller::Hide()
{
    m_document->Hide();
}
