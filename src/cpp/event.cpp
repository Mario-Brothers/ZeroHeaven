#include "../headers/event.hpp"
#include "../headers/Entity/player/playerHandling.hpp"

SDL_AppResult handleEvent(SDL_Event* event, void* appstate, Player* player)
{
    if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE)
    {
        return SDL_APP_SUCCESS;
    }

    handlePlayerMovement(event, player);

    return SDL_APP_CONTINUE;
}
