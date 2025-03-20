#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_main.h>
#include "Init.hpp"
#include "Settings.hpp"

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static SDL_GLContext glContext = nullptr;

GameState gameState = GameState::MENU;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char** argv)
{
	InitEverything(renderer, window, glContext);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE) 
	{
		return SDL_APP_SUCCESS; 
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
	if (gameState == GameState::MENU)
	{
		// Menu
	}
	else if (gameState == GameState::GAME)
	{
		// Game
	}

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{

}