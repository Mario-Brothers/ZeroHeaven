#include "../../headers/Map/Platform.hpp"

#include <iostream>

int numOfPlatforms = 50; // Number of platforms to generate
int min_platform_width = 100; // Minimum platform width
int max_platform_width = 400; // Maximum platform width
int min_platform_height = 50; // Minimum platform height
int max_platform_height = 50; // Maximum platform height

void Platform::render(SDL_Renderer* renderer, Camera* camera)
{
    SDL_FRect drawRect =
    {
        rect.x + camera->offSetX,
        rect.y + camera->offSetY,
        rect.w,
        rect.h
    };

    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &drawRect);
}
