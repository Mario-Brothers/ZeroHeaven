#pragma once

#include <vector>

extern float WINDOW_WIDTH;
extern float WINDOW_HEIGHT;

struct Resolution
{
    float width;
    float height;
};

extern std::vector<Resolution> resolutions;

std::vector<Resolution> getResolution();
