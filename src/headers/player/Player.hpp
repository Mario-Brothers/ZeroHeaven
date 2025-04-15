#pragma once

#include <SDL3/SDL.h>

class Player
{
public:
    Player();
    ~Player();
   
    void renderPlayer(SDL_Renderer* renderer);


private:
    SDL_FRect playerRect;
    float playerHeight;
    float playerWidth;
};
