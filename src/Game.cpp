#include "Game.hpp"

#include "UI/UISystem.hpp"
#include <RmlUi/Core.h>
#include "RmlUi_Backend/RmlUi_Backend.h"
#include <SDL3/SDL.h>

bool initialized = false;
const char* CONTEXT_NAME = "main";

bool Game::Initialize()
{
	if(initialized)
		return true;
	
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game: Initializing");
	SDL_SetLogPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game: BasePath: %s", Game::GetBasePath());
	if(!UISystem::Initialize())
		return false;
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Game: Initialize: done");
	initialized = true;

    return true;
}

void Game::Shutdown()
{
	UISystem::Shutdown();
	initialized = false;
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Game: Shutdown");
}

int Game::Run()
{
	if(!initialized)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "You can't run the game unless it is initialized");
		return -1;
	}

	UISystem::SetMenu(UISystem::MAIN_MENU_CONTROLLER.get());
	
    bool running = true;
	while (running)
	{
		running = UISystem::ProcessEventsUpdateAndRender();
	}

	Game::Shutdown();
    return 0;
}

const char *Game::GetBasePath()
{
    return SDL_GetBasePath();
}

std::string Game::GetResoucesPath()
{
	return SDL_GetBasePath() + std::string("../resources/");
}