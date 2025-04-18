#pragma once

#include <SDL3/SDL.h>
#include "../../headers/Camera/Camera.hpp"

extern int numOfPlatforms; // Number of platforms to generate
extern int min_platform_width; // Minimum platform width
extern int max_platform_width; // Maximum platform width
extern int min_platform_height; // Minimum platform height
extern int max_platform_height; // Maximum platform height

struct Platform
{
    SDL_FRect rect;

    Platform(float x, float y, float w, float h) : rect{x, y, w, h} {}

    void render(SDL_Renderer* renderer, Camera* camera);
};
