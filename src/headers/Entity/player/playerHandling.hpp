#pragma once

#include <SDL3/SDL.h>

class Player;

void handlePlayerMovement(SDL_Event* event, Player* player);
