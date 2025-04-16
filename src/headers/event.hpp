#pragma once

#include <SDL3/SDL.h>

class Player;

SDL_AppResult handleEvent(SDL_Event* event, void* appstate, Player* player);
