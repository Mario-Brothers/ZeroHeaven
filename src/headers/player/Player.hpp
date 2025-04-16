#pragma once

#include <SDL3/SDL.h>

class Player
{
public:
    Player(float windowWidth, float windowHeight);
    ~Player();
   
    void renderPlayer(SDL_Renderer* renderer);
    void update(float deltaTime);

    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void jump();
    void setMovingLeft(bool movingLeft);
    void setMovingRight(bool movingRight);

private:
    float x = 0.0f, y = 0.0f;
    float velocityY = 0.0f;
    float playerSpeed = 200.0f;
    bool isOnGround = false;
    bool isMovingLeft = false;
    bool isMovingRight = false;

    SDL_FRect playerRect;
    float playerHeight = 50.0f;
    float playerWidth = 50.0f;
};
