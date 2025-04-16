#include "../../headers/player/Player.hpp"
#include "../../headers/Settings.hpp"

Player::Player()
{
    playerRect.x = WINDOW_WIDTH / 2 - playerWidth / 2; // Initial x position
    playerRect.y = WINDOW_HEIGHT / 2 - playerHeight / 2; // Initial y position
    playerRect.w = playerWidth; // Width of the player
    playerRect.h = playerHeight; // Height of the player
}

void Player::renderPlayer(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
}

void Player::moveUp()
{
    if (playerRect.y > 0) // Check if the player is not at the top edge
    {
        playerRect.y -= 5.0f; // Move up
    }
}

void Player::moveDown()
{
    if (playerRect.y < WINDOW_HEIGHT - playerHeight) // Check if the player is not at the bottom edge
    {
        playerRect.y += 5.0f; // Move down
    }
}

void Player::moveLeft()
{
    if (playerRect.x > 0) // Check if the player is not at the left edge
    {
        playerRect.x -= 5.0f; // Move left
    }
}

void Player::moveRight()
{
    if (playerRect.x < WINDOW_WIDTH - playerWidth) // Check if the player is not at the right edge
    {
        playerRect.x += 5.0f; // Move right
    }
}
