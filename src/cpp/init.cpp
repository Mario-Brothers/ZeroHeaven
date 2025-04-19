#include "../headers/init.hpp"
#include "../headers/Entity/player/Player.hpp"
#include "../headers/Camera/Camera.hpp"
#include "../headers/Settings.hpp"
#include "../headers/Map/Map.hpp"
#include "../headers/Map/Platform.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <iostream>

SDL_AppResult initEverything(SDL_Window*& window, SDL_Renderer*& renderer, void** appstate, Player*& player, Camera*& camera, Map*& map)
{
    if(!SDL_Init(SDL_INIT_VIDEO)) // Initialize SDL
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    std::vector<Resolution> resolutions = getResolution(); // Get available resolutions
    if (!resolutions.empty())
    {
        WINDOW_WIDTH = resolutions[0].width; // Set the width of the window
        WINDOW_HEIGHT = resolutions[0].height; // Set the height of the window
        SDL_Log("Ustawiono rozdzielczość okna na: %f x %f\n", WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    else
    {
        SDL_Log("Nie udało się pobrać rozdzielczości, używam domyślnych wartości.\n");
        WINDOW_WIDTH = 800; // Default width
        WINDOW_HEIGHT = 600; // Default height
    }

    SDL_DisplayID primary_display = SDL_GetPrimaryDisplay();
    if (!primary_display)
    {
        std::cerr << "Nie udało się pobrać głównego wyświetlacza: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }
    SDL_Log("Główny wyświetlacz ID: %" SDL_PRIu32 "\n", primary_display);

    SDL_PropertiesID props = SDL_CreateProperties();
    if (!props)
    {
        std::cerr << "Nie udało się utworzyć obiektu właściwości: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, "Game?");
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_X_NUMBER, SDL_WINDOWPOS_CENTERED_DISPLAY(primary_display));
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, SDL_WINDOWPOS_CENTERED_DISPLAY(primary_display));
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, WINDOW_WIDTH);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, WINDOW_HEIGHT);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER, SDL_WINDOW_BORDERLESS); // Bez pełnego ekranu na starcie

    window = SDL_CreateWindowWithProperties(props);
    SDL_DestroyProperties(props);

    if (!window)
    {
        std::cerr << "Nie udało się utworzyć okna: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    // Ustawienie trybu pełnoekranowego (pełny ekran pulpitu)
    if (SDL_SetWindowFullscreenMode(window, nullptr)) 
    {
        SDL_Log("Nie można ustawić trybu pełnoekranowego: %s", SDL_GetError());
    }

    // Aktywacja trybu pełnoekranowego
    if (SDL_SetWindowFullscreen(window, true)) 
    {
        SDL_Log("Nie można włączyć pełnego ekranu: %s", SDL_GetError());
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

    camera = new Camera(WINDOW_WIDTH, WINDOW_HEIGHT, MAP_MAX_X, MAP_MAX_Y); // Create a camera object
    if(!camera)
    {
        SDL_Log("Failed to create camera object");
        return SDL_APP_FAILURE;
    }

    map = new Map(); // Create a map object
    if(!map)
    {
        SDL_Log("Failed to create map object");
        return SDL_APP_FAILURE;
    }

    map->generatePlatforms(MAP_MIN_X, MAP_MAX_X, MAP_MIN_Y, MAP_MAX_Y, numOfPlatforms, min_platform_width, max_platform_width, min_platform_height, max_platform_height); // Generate platforms

    return SDL_APP_CONTINUE;
}
