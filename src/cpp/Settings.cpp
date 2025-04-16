#include "../headers/Settings.hpp"
#include <SDL3/SDL.h>

std::vector<Resolution> getResolution()
{
    std::vector<Resolution> resV; // Vector to store resolutions

    int i, num_displays = 0; // Number of displays
    SDL_DisplayID *displays = SDL_GetDisplays(&num_displays); // Get displays
    
    if(displays)
    {
        for(i = 0; i < num_displays; ++i) // Iterate through displays
        {
            SDL_DisplayID instance_id = displays[i]; // Get display ID
            const char *name = SDL_GetDisplayName(instance_id); // Get display name

            SDL_Log("Display %" SDL_PRIu32 ": %s\n", instance_id, name ? name : "Unknown"); // Log display info
        }
    }
    SDL_free(displays); // Free display list

    SDL_DisplayID display = SDL_GetPrimaryDisplay(); // Get primary display
    int num_modes = 0; // Number of modes
    SDL_DisplayMode **modes = SDL_GetFullscreenDisplayModes(display, &num_modes); // Get display modes

    if (modes)  
    {
        Resolution res; // Resolution struct

        for (i = 0; i < num_modes; ++i) // Iterate through modes
        {
            SDL_DisplayMode *mode = modes[i]; // Get display mode
            SDL_Log("Display %" SDL_PRIu32 " mode %d: %dx%d@%gx %gHz\n",
                    display, i, mode->w, mode->h, mode->pixel_density, mode->refresh_rate); // Log mode info
            
            res.width = mode->w; // Set width
            res.height = mode->h; // Set height
            resV.push_back(res); // Add resolution to vector

        }
        SDL_free(modes);
    }
    
    return resV;
}
