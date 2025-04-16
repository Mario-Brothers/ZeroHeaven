#include "../../headers/player/playerHandling.hpp"
#include "../../headers/player/Player.hpp"

void handlePlayerMovement(SDL_Event* event, Player* player)
{
    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        switch (event->key.scancode)
        {
            case SDL_SCANCODE_LEFT:
                player->setMovingLeft(true);
                break;

            case SDL_SCANCODE_RIGHT:
                player->setMovingRight(true);
                break;

            case SDL_SCANCODE_SPACE:
                player->jump();
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
                player->setMovingLeft(false);
                break;

            case SDL_SCANCODE_RIGHT:
                player->setMovingRight(false);
                break;

            case SDL_SCANCODE_SPACE:
            default:
                break;
        }
    }
}
