#pragma once

#include "../IController.hpp"

class MainMenuController : public IController
{
    Rml::ElementDocument* m_view;
public:
    MainMenuController();
    void OnShow();
    void OnHide();
    Rml::ElementDocument& GetDocument();
};