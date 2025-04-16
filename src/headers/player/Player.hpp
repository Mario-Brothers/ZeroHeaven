#pragma once

#include <SDL3/SDL.h>

class Player
{
public:
    Player();
    ~Player();
   
    void renderPlayer(SDL_Renderer* renderer);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    SDL_FRect playerRect;
    float playerHeight = 50.0f;
    float playerWidth = 50.0f;
};
