#include "Game.hpp"

#include <RmlUi/Debugger.h>
#include "RmlUi_Backend/RmlUi_Backend.h"
#include <SDL3/SDL.h>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

Rml::Context* pContext = nullptr;
bool initialized = false;
const char* CONTEXT_NAME = "main";

bool Game::Initialize()
{
	if(initialized)
		return true;

	SDL_SetLogPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);
	
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

	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "The game initialized");
	initialized = true;

    return true;
}

int Game::Run()
{
	if(!initialized)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "You can't run the game unless it is initialized");
		return -1;
	}
	
    bool running = true;
	while (running)
	{
		running = Backend::ProcessEvents(pContext, nullptr, false);

		pContext->Update();

		Backend::BeginFrame();
		pContext->Render();
		Backend::PresentFrame();
	}

	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Unitializing the game");

	Rml::RemoveContext(CONTEXT_NAME);
	Rml::Shutdown();
	Backend::Shutdown();

	initialized = false;

    return 0;
}
