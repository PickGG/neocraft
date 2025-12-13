#include "Game.hpp"

#include "UI/UISystem.hpp"
#include <RmlUi/Core.h>
#include "RmlUi_Backend/RmlUi_Backend.h"
#include <SDL3/SDL.h>
#include "Logging.hpp"

bool m_initialized = false;
const char* CONTEXT_NAME = "main";
bool m_quit;

bool Game::Initialize()
{
	if(m_initialized)
		return true;

	LOG_INFO("Game: Initializing");
	SDL_SetLogPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);
	LOG_INFO("Game: BasePath: %s", Game::GetBasePath());
	if(!UISystem::Initialize())
		return false;
	
	m_initialized = true;
	m_quit = false;
	LOG_INFO("Game: Initialized");
	
    return true;
}

void Game::Shutdown()
{
	UISystem::Shutdown();
	m_initialized = false;
	LOG_INFO("Game: Shutdown");
}

int Game::Run()
{
	if(!m_initialized)
	{
		LOG_ERROR("You can't run the game unless it is initialized");
		return -1;
	}

	UISystem::SetMenu(UISystem::MAIN_MENU_CONTROLLER.get());
	
    bool running = true;
	while (running && !m_quit)
	{
		running = UISystem::ProcessEventsUpdateAndRender();
	}

	Game::Shutdown();
    return 0;
}

void Game::Quit()
{
	m_quit = true;
}

const char *Game::GetBasePath()
{
    return SDL_GetBasePath();
}

std::string Game::GetResoucesPath()
{
	return SDL_GetBasePath() + std::string("../resources/");
}