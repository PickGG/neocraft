#include "UISystem.hpp"

#include <RmlUi/Debugger.h>
#include <memory>
#include "../RmlUi_Backend/RmlUi_Backend.h"
#include "MainMenu/MainMenuController.hpp"
#include "../Game.hpp"
#include "../Logging.hpp"

namespace UISystem
{
    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;

    Rml::Context*   pContext;
    bool            initialized = false;
    const char*     CONTEXT_NAME = "main";
    Controller*    currentController = nullptr;

    std::unique_ptr<Controller> MAIN_MENU_CONTROLLER;

    bool Initialize()
    {
        if(initialized)
            return true;
        
        LOG_INFO("UISystem: Initializing");

        // Constructs the system and render interfaces, creates a window, and attaches the renderer.
        if (!Backend::Initialize("NeoCraft", WINDOW_WIDTH, WINDOW_HEIGHT, true))
        {
            SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize backend");
            return false;
        }

        // Install the custom interfaces constructed by the backend before initializing RmlUi.
        Rml::SetSystemInterface(Backend::GetSystemInterface());
        Rml::SetRenderInterface(Backend::GetRenderInterface());

        // RmlUi initialisation.
        Rml::Initialise();

        // Create the main RmlUi context.
        pContext = Rml::CreateContext(CONTEXT_NAME, Rml::Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT));
        if (!pContext)
        {
            SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to create RmlUi context");
            Rml::Shutdown();
            Backend::Shutdown();
            return false;
        }

        LOG_INFO("UISystem: Initialize: done");

        // Load Fonts
        if(!Rml::LoadFontFace(Game::GetResoucesPath() + "acme_7_wide_xtnd.ttf", false))
        {
            LOG_CRIT("Failed to load font");
            Rml::Shutdown();
            Backend::Shutdown();
            return false;
        }

        // Show main menu
        UISystem::MAIN_MENU_CONTROLLER = std::make_unique<MainMenuController>();

        initialized = true;

        return true;
    }

    void Shutdown()
    {
        LOG_INFO("UISystem: Shutting down");

        // Remove controllers
        currentController = nullptr;
        MAIN_MENU_CONTROLLER.reset(); 

        // Cleanup
        LOG_INFO("UISystem: Removing context");
        Rml::RemoveContext(CONTEXT_NAME);
        LOG_INFO("UISystem: Rml shutting down");
        Rml::Shutdown();
        LOG_INFO("UISystem: Shutting down backend");
        Backend::Shutdown();

        initialized = false;
    }

    bool ProcessEventsUpdateAndRender()
    {
        if(!initialized)
        {
            LOG_ERROR("You can't use UISystem unless it is initialized");
            return false;
        }

        bool running = Backend::ProcessEvents(pContext, nullptr, false);

		pContext->Update();
		Backend::BeginFrame();
		pContext->Render();
		Backend::PresentFrame();

        return running;
    }

    Rml::Context& GetContext()
    {
        return *pContext;
    }

    void SetMenu(Controller *controller)
    {
        LOG_INFO("UISystem: SetMenu");

        if(currentController) {
            currentController->Hide();
        }
        
        currentController = controller;
        currentController->Show();
    }
}