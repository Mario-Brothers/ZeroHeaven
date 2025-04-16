#include "../../headers/player/Player.hpp"
#include "../../headers/Settings.hpp"

const float GRAVITY = 1000.0f; // Gravity constant
const float JUMP_FORCE = -500.0f; // Jump velocity
const float GROUND_Y = 500.0f; // Ground level


Player::Player(float windowWidth, float windowHeight)
{
    playerRect.w = playerWidth; // Set the width of the player rectangle
    playerRect.h = playerHeight; // Set the height of the player rectangle

    x = windowWidth / 2.0f - playerWidth / 2.0f; // Center the player horizontally
    y = windowHeight / 2.0f - playerHeight / 2.0f; // Center the player vertically

    playerRect.x = static_cast<int>(x); // Set the initial x position
    playerRect.y = static_cast<int>(y); // Set the initial y position
}

void Player::renderPlayer(SDL_Renderer* renderer)
{
    SDL_Log("Rendering player at position: (%f, %f)", x, y); // Debug   
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
}

void Player::update(float deltaTime)
{
    if (isMovingLeft) // Check if the player is moving left
    {
        moveLeft(deltaTime); // Apply smooth movement
    }

    if (isMovingRight) // Check if the player is moving right
    {
        moveRight(deltaTime); // Apply smooth movement
    }

    if (!isOnGround) // Check if the player is in the air
    {
        // Apply gravity to the player's vertical velocity
        velocityY += GRAVITY * deltaTime;
        y += velocityY * deltaTime;

        // Check for collision with the ground
        if (y >= GROUND_Y)
        {
            y = GROUND_Y; // Reset to ground level
            velocityY = 0; // Reset vertical velocity
            isOnGround = true; // Set on ground flag
        }
    }

    playerRect.y = static_cast<int>(y); // Update the player's y position
}

void Player::moveLeft(float deltaTime) // Move the player left
{
    if (playerRect.x < WINDOW_WIDTH - playerWidth)
    {
        playerRect.x += playerSpeed * deltaTime; // Apply smooth movement by multiplying by deltaTime
        x = playerRect.x;
    }
}

void Player::moveRight(float deltaTime) // Move the player right
{
    if (playerRect.x < WINDOW_WIDTH - playerWidth)
    {
        playerRect.x += playerSpeed * deltaTime; // Apply smooth movement by multiplying by deltaTime
        x = playerRect.x;
    }
}

void Player::jump() // Make the player jump
{
    if (isOnGround) // Check if the player is on the ground 
    {
        velocityY = JUMP_FORCE; // Set the jump velocity
        isOnGround = false; // Set the on ground flag to false
    }
}

void Player::setMovingLeft(bool movingLeft) // Set the moving left flag
{
    isMovingLeft = movingLeft; // Set the moving left flag
}

void Player::setMovingRight(bool movingRight) // Set the moving right flag
{
    isMovingRight = movingRight; // Set the moving right flag
}
