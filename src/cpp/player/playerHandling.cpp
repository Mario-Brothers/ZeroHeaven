#include "../../headers/player/playerHandling.hpp"
#include "../../headers/player/Player.hpp"

void handlePlayerMovement(SDL_Event* event, Player* player)
{
    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        switch (event->key.scancode)
        {
            case SDL_SCANCODE_UP:
                player->moveUp();
                break;
            
            case SDL_SCANCODE_DOWN:
                player->moveDown();
                break;
            
            case SDL_SCANCODE_LEFT:
                player->moveLeft();
                break;

            case SDL_SCANCODE_RIGHT:
                player->moveRight();
                break;

            default:
                break;
        }
    }

    else if (event->type == SDL_EVENT_KEY_UP)
    {
        switch (event->key.scancode)
        {
            case SDL_SCANCODE_UP:
                break;
            
            case SDL_SCANCODE_DOWN:
                break;

            case SDL_SCANCODE_LEFT:
                break;

            case SDL_SCANCODE_RIGHT:
                break;

            default:
                break;
        }
    }
}
