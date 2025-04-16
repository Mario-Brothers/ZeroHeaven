#include "../headers/init.hpp"
#include "../headers/player/Player.hpp"

SDL_AppResult initEverything(SDL_Window*& window, SDL_Renderer*& renderer, void** appstate, Player*& player)
{ 
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    std::vector<Resolution> resolutions = getResolution();
    if (!resolutions.empty())
    {
        WINDOW_WIDTH = resolutions[18].width;
        WINDOW_HEIGHT = resolutions[18].height;
        SDL_Log("Ustawiono rozdzielczość okna na: %f x %f\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    else
    {
        SDL_Log("Nie udało się pobrać rozdzielczości, używam domyślnych wartości.\n");
        WINDOW_WIDTH = 800; // Ustaw jakieś domyślne wartości
        WINDOW_HEIGHT = 600;
    }
    
    window = SDL_CreateWindow("game?", WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
    if (!window)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    player = new Player();
    if(!player)
    {
        SDL_Log("Failed to create player object");
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}
