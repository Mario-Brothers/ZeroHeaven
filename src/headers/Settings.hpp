#pragma once

#include <vector>

extern float WINDOW_WIDTH; // Window width
extern float WINDOW_HEIGHT; // Window height

struct Resolution 
{
    float width; // Width of the resolution
    float height;  // Height of the resolution 
};

extern std::vector<Resolution> resolutions; // Vector to store available resolutions

std::vector<Resolution> getResolution(); // Function to get available resolutions
