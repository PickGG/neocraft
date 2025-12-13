#pragma once

#include <RmlUi/Core.h>

class Controller
{
public:
    Controller(const char* documentPath);
    virtual ~Controller();
    void Show();
    void Hide();
protected:
    Rml::ElementDocument* m_document;
};