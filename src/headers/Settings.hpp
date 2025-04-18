#pragma once

#include <vector>

extern float WINDOW_WIDTH; // Window width
extern float WINDOW_HEIGHT; // Window height


const float MAP_MIN_Y = 0.0f; // Minimum Y coordinate of the map
const float MAP_MAX_Y = 1000.0f; // Maximum Y coordinate of the map
const float MAP_MIN_X = 0.0f; // Minimum X coordinate of the map
const float MAP_MAX_X = 10000.0f; // Maximum X coordinate of the map


struct Resolution 
{
    float width; // Width of the resolution
    float height;  // Height of the resolution 
};

extern std::vector<Resolution> resolutions; // Vector to store available resolutions

std::vector<Resolution> getResolution(); // Function to get available resolutions
