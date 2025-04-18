#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_log.h>

#include "../headers/Settings.hpp"
#include "../headers/init.hpp"
#include "../headers/Entity/player/Player.hpp"
#include "../headers/event.hpp"
#include "../headers/Camera/Camera.hpp"

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;
Player *player = nullptr;
Camera *camera = nullptr;

float WINDOW_WIDTH;
float WINDOW_HEIGHT;
float lastTime = SDL_GetTicks() / 1000.0f; // Last frame time

SDL_AppResult SDL_AppInit(void **appstate, int argc, char* argv[])
{
    if (initEverything(window, renderer, appstate, player, camera) == SDL_APP_FAILURE) // 
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

    float currentTime = SDL_GetTicks() / 1000.0f; // Get current time
    float deltaTime = currentTime - lastTime; // Calculate delta time
    lastTime = currentTime; // Update last time

    camera->update(player->pos.x, player->pos.y, player->playerWidth, player->playerHeight, deltaTime); // Update camera position
    
    player->update(deltaTime, camera); // Update player state

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set the draw color to white
    SDL_RenderClear(renderer); // Clear the screen

    player->render(renderer, camera); // Render the player

    SDL_RenderPresent(renderer); // Present the renderer

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    // Fuck you mother
}
