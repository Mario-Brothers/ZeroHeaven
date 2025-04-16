#include "../../headers/player/Player.hpp"
#include "../../headers/Settings.hpp"

Player::Player()
{
    playerRect.x = WINDOW_WIDTH / 2; // Initial x position
    playerRect.y = WINDOW_HEIGHT / 2; // Initial y position
    playerRect.w = 50; // Width of the player
    playerRect.h = 50; // Height of the player
}

void Player::renderPlayer(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
}
