#include "../headers/Settings.hpp"
#include "../headers/init.hpp"

#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL_log.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;

float WINDOW_WIDTH;
float WINDOW_HEIGHT;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char* argv[])
{
    if (initEverything(window, renderer, appstate) == SDL_APP_FAILURE)
    {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE)
    {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}
