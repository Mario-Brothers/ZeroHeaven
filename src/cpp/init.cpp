#include "../headers/init.hpp"
#include "../headers/Entity/player/Player.hpp"

SDL_AppResult initEverything(SDL_Window*& window, SDL_Renderer*& renderer, void** appstate, Player*& player)
{ 
    if(!SDL_Init(SDL_INIT_VIDEO)) // Initialize SDL
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    std::vector<Resolution> resolutions = getResolution(); // Get available resolutions
    if (!resolutions.empty()) 
    {
        WINDOW_WIDTH = resolutions[18].width; // Set the width of the window
        WINDOW_HEIGHT = resolutions[18].height; // Set the height of the window
        SDL_Log("Ustawiono rozdzielczość okna na: %f x %f\n", WINDOW_WIDTH, WINDOW_HEIGHT); 
    }
    else
    {
        SDL_Log("Nie udało się pobrać rozdzielczości, używam domyślnych wartości.\n"); 
        WINDOW_WIDTH = 800; // Default width
        WINDOW_HEIGHT = 600; // Default height
    }
    
    window = SDL_CreateWindow("game?", WINDOW_WIDTH, WINDOW_HEIGHT, NULL); // Create a window
    if (!window)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window, NULL); // Create a renderer
    if (!renderer)
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    player = new Player(WINDOW_WIDTH, WINDOW_HEIGHT); // Create a player object
    if(!player)
    {
        SDL_Log("Failed to create player object");
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}
