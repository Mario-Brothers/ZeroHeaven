#pragma once

#include <vector>
#include "Platform.hpp"
#include "../Camera/Camera.hpp"

class Map
{
public:
    std::vector<Platform> platforms;

    Map();
    void generatePlatforms(float mapMinX, float mapMaxX, float mapMinY, float mapMaxY, int numOfPlatforms, int minWidth, int maxWidth, int minHeight, int maxHeight);
    void render(SDL_Renderer* renderer, Camera* camera);
};
