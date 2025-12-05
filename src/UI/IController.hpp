#pragma once

#include <RmlUi/Core.h>

class ElementDocument;

class IController
{
public:
    virtual void OnShow()=0;
    virtual void OnHide()=0;
    virtual Rml::ElementDocument& GetDocument()=0;
};