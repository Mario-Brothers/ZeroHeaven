#include "../../headers/Map/Map.hpp"
#include "../../headers/Map/Platform.hpp"

#include <random>
#include <iostream>

Map::Map()
{

}

void Map::generatePlatforms(float mapMinX, float mapMaxX, float mapMinY, float mapMaxY, int numOfPlatforms, int minWidth, int maxWidth, int minHeight, int maxHeight)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(mapMinX, mapMaxX - minWidth);
    std::uniform_real_distribution<> dis_y(mapMinY, mapMaxY - minHeight); // Poprawiony zakres Y
    std::uniform_real_distribution<> dis_width(minWidth, maxWidth);
    std::uniform_real_distribution<> dis_height(minHeight, maxHeight);

    for (int i = 0; i < numOfPlatforms; ++i)
    {
        float x = dis_x(gen);
        float y = dis_y(gen);
        float w = dis_width(gen);
        float h = dis_height(gen);
    
        platforms.push_back(Platform(x, y, w, h));
    }
}

void Map::render(SDL_Renderer* renderer, Camera* camera)
{
    for (Platform& platform : platforms)
    {
        platform.render(renderer, camera);
    }
}
