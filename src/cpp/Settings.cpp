#include "../headers/Settings.hpp"
#include <SDL3/SDL.h>
#include <algorithm>

std::vector<Resolution> getResolution()
{
    std::vector<Resolution> resolutions;
    SDL_DisplayID display = SDL_GetPrimaryDisplay();

    if (display == 0)
    {
        SDL_Log("Nie uda³o siê pobraæ g³ównego wyœwietlacza: %s", SDL_GetError());
        return resolutions;
    }

    int num_modes = 0;
    SDL_DisplayMode** modes = SDL_GetFullscreenDisplayModes(display, &num_modes);
    if (modes == nullptr || num_modes == 0)
    {
        SDL_Log("Nie uda³o siê pobraæ trybów wyœwietlania lub brak dostêpnych trybów: %s", SDL_GetError());
        return resolutions; // Zwraca pusty wektor w przypadku b³êdu
    }

    for (int i = 0; i < num_modes; ++i)
    {
        SDL_DisplayMode* mode = modes[i];
        if (mode != nullptr)
        {
            Resolution res = { static_cast<float>(mode->w), static_cast<float>(mode->h) };
            float freshRate = mode->refresh_rate;
            // Sprawdzamy, czy rozdzielczoœæ ju¿ istnieje w wektorze
            if (std::find_if(resolutions.begin(), resolutions.end(),
                [&res](const Resolution& r) { return r.width == res.width && r.height == res.height; }) == resolutions.end())
            {
                resolutions.push_back(res);
            }
        }
    }

    SDL_free(modes);

    return resolutions;   
}
