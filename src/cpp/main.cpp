#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_log.h>

#include "../headers/Settings.hpp"
#include "../headers/init.hpp"
#include "../headers/player/Player.hpp"
#include "../headers/event.hpp"

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;
Player *player = nullptr;

float WINDOW_WIDTH;
float WINDOW_HEIGHT;
float lastTime = SDL_GetTicks() / 1000.0f;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char* argv[])
{
    if (initEverything(window, renderer, appstate, player) == SDL_APP_FAILURE)
    {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    return handleEvent(event, appstate, player);
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    float currentTime = SDL_GetTicks() / 1000.0f;
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    player->update(deltaTime);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set the draw color to white
    SDL_RenderClear(renderer);

    player->renderPlayer(renderer);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}
