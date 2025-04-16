#include "../../headers/player/Player.hpp"
#include "../../headers/Settings.hpp"

const float GRAVITY = 1000.0f; // Gravity constant
const float JUMP_FORCE = -500.0f; // Jump velocity
const float GROUND_Y = 500.0f; // Ground level



Player::Player(float windowWidth, float windowHeight)
{
    playerRect.w = playerWidth;
    playerRect.h = playerHeight;

    x = windowWidth / 2.0f - playerWidth / 2.0f;
    y = windowHeight / 2.0f - playerHeight / 2.0f;

    playerRect.x = static_cast<int>(x);
    playerRect.y = static_cast<int>(y);
}

void Player::renderPlayer(SDL_Renderer* renderer)
{
    SDL_Log("Rendering player at position: (%f, %f)", x, y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
}

void Player::update(float deltaTime)
{
    if (isMovingLeft)
    {
        moveLeft(deltaTime);
    }

    if (isMovingRight)
    {
        moveRight(deltaTime);
    }

    if (!isOnGround)
    {
        velocityY += GRAVITY * deltaTime;
        y += velocityY * deltaTime;

        if (y >= GROUND_Y)
        {
            y = GROUND_Y;
            velocityY = 0;
            isOnGround = true;
        }
    }

    playerRect.y = static_cast<int>(y); // Update the player's y position
}

void Player::moveLeft(float deltaTime)
{
    if (playerRect.x > 0)
    {
        playerRect.x -= playerSpeed * deltaTime; // Apply smooth movement by multiplying by deltaTime
        x = playerRect.x;
    }
}

void Player::moveRight(float deltaTime)
{
    if (playerRect.x < WINDOW_WIDTH - playerWidth)
    {
        playerRect.x += playerSpeed * deltaTime; // Apply smooth movement by multiplying by deltaTime
        x = playerRect.x;
    }
}

void Player::jump()
{
    if (isOnGround) 
    {
        velocityY = JUMP_FORCE;
        isOnGround = false;
    }
}

void Player::setMovingLeft(bool movingLeft)
{
    isMovingLeft = movingLeft;
}

void Player::setMovingRight(bool movingRight)
{
    isMovingRight = movingRight;
}

