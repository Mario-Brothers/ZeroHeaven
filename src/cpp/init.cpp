#include "../headers/init.hpp"
#include "../headers/Entity/player/Player.hpp"
#include "../headers/Camera/Camera.hpp"
#include "../headers/Settings.hpp"
#include "../headers/Map/Map.hpp"
#include "../headers/Map/Platform.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

void ForceWindowToDisplay(SDL_Window* window, SDL_DisplayID target_display)
{
    SDL_Rect display_bounds;
    SDL_GetDisplayBounds(target_display, &display_bounds);
    
    // Wymuś pozycję w fizycznych współrzędnych ekranu
    SDL_SetWindowPosition(window, 
                        display_bounds.x + 100,  // Mały offset aby uniknąć krawędzi
                        display_bounds.y + 100);
    
    // Wymuś zmianę monitora przed pełnym ekranem
    SDL_SyncWindow(window);
    SDL_Delay(100);  // Krótka pauza dla systemu
    
    SDL_DisplayID actual_display = SDL_GetDisplayForWindow(window);
    if (actual_display != target_display)
    {
        SDL_Log("KRYTYCZNE: System ignoruje pozycję okna! Wymuszam ręcznie...");
        
        // Ostateczna próba - tymczasowe okno pomostowe
        SDL_PropertiesID props = SDL_CreateProperties();
        SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_X_NUMBER, display_bounds.x);
        SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, display_bounds.y);
        SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, 100);
        SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, 100);
        SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER, 
                             SDL_WINDOW_UTILITY | SDL_WINDOW_UTILITY);
        
        SDL_Window* dummy = SDL_CreateWindowWithProperties(props);
        if (dummy)
        {
            SDL_RaiseWindow(window);
            SDL_DestroyWindow(dummy);
        }
        SDL_DestroyProperties(props);
    }
}

SDL_AppResult initEverything(SDL_Window*& window, SDL_Renderer*& renderer, void** appstate, Player*& player, Camera*& camera, Map*& map)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    int display_count;
    SDL_DisplayID* displays = SDL_GetDisplays(&display_count);
    
    if(!displays || display_count == 0) 
    {
        SDL_Log("Nie znaleziono żadnych monitorów");
        return SDL_APP_FAILURE;
    }

    SDL_DisplayID target_display = displays[0];
    
    for(int i = 0; i < display_count; i++) 
    {
        const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(displays[i]);
        
        if(mode && mode->w == 1920 && mode->h == 1080) 
        {
            target_display = displays[i];
            break;
        }
    }

    const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(target_display);
    
    if(!mode) 
    {
        SDL_Log("Nie można pobrać trybu wyświetlania: %s", SDL_GetError());
        SDL_free(displays);
        return SDL_APP_FAILURE;
    }

    WINDOW_WIDTH = mode->w;
    WINDOW_HEIGHT = mode->h;

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetStringProperty(props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, "Game");
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_X_NUMBER, SDL_WINDOWPOS_CENTERED_DISPLAY(target_display));
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, SDL_WINDOWPOS_CENTERED_DISPLAY(target_display));
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, WINDOW_WIDTH);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, WINDOW_HEIGHT);
    SDL_SetNumberProperty(props, SDL_PROP_WINDOW_CREATE_FLAGS_NUMBER, SDL_WINDOW_BORDERLESS);

    window = SDL_CreateWindowWithProperties(props);
    SDL_DestroyProperties(props);
    SDL_free(displays);

    if(!window) 
    {
        SDL_Log("Nie udało się utworzyć okna: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Rect display_bounds;
    SDL_GetDisplayBounds(target_display, &display_bounds);
    SDL_SetWindowPosition(window, display_bounds.x, display_bounds.y);
    SDL_SyncWindow(window);
    SDL_Delay(100);

    if(SDL_SetWindowFullscreenMode(window, mode) != 0) 
    {
        SDL_Log("Nie udało się ustawić trybu pełnoekranowego: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    
    if(!renderer) 
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    player = new Player(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    if(!player) 
    {
        SDL_Log("Failed to create player object");
        return SDL_APP_FAILURE;
    }

    camera = new Camera(WINDOW_WIDTH, WINDOW_HEIGHT, MAP_MAX_X, MAP_MAX_Y);
    
    if(!camera) 
    {
        SDL_Log("Failed to create camera object");
        return SDL_APP_FAILURE;
    }

    map = new Map();
    
    if(!map) 
    {
        SDL_Log("Failed to create map object");
        return SDL_APP_FAILURE;
    }

    map->generatePlatforms(MAP_MIN_X, MAP_MAX_X, MAP_MIN_Y, MAP_MAX_Y, 
                         numOfPlatforms, min_platform_width, max_platform_width,
                         min_platform_height, max_platform_height);

    return SDL_APP_CONTINUE;
}
