#include "../../../headers/Entity/player/Player.hpp"
#include "../../../headers/Entity/player/playerHandling.hpp"

void handlePlayerMovement(SDL_Event* event, Player* player)
{
    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        switch (event->key.scancode)
        {
            case SDL_SCANCODE_LEFT:
                player->setMovingLeft(true); // Set the moving left flag
                break;

            case SDL_SCANCODE_RIGHT:
                player->setMovingRight(true); // Set the moving right flag
                break;

            case SDL_SCANCODE_SPACE:
                player->jump(); // Make the player jump
                break;

            default:
                break;
        }
    }

    else if (event->type == SDL_EVENT_KEY_UP)
    {
        switch (event->key.scancode)
        {
            case SDL_SCANCODE_LEFT:
                player->setMovingLeft(false); // Set the moving left flag to false
                break;

            case SDL_SCANCODE_RIGHT:
                player->setMovingRight(false); // Set the moving right flag to false
                break;

            case SDL_SCANCODE_SPACE:
            default:
                break;
        }
    }
}
