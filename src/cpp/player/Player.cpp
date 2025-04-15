#include "../../headers/player/Player.hpp"

void Player::renderPlayer(SDL_Renderer* renderer)
{
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
}
