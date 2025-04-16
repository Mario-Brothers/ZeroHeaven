#pragma once

#include <SDL3/SDL.h>
#include "../headers/Settings.hpp"

class Player;

SDL_AppResult initEverything(SDL_Window*& window, SDL_Renderer*& renderer, void** appstate, Player*& player);
