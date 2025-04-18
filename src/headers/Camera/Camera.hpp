#pragma once

class Camera 
{
public:
    float offSetX;
    float offSetY;
    float screenWidth;
    float screenHeight;
    float mapWidth;
    float mapHeight;

    Camera(float screenWidth, float screenHeight, float mapWidth, float mapHeight)
        : offSetX(0), offSetY(0), screenWidth(screenWidth), screenHeight(screenHeight), mapWidth(mapWidth), mapHeight(mapHeight) {}
    
    void update(float playerX, float playerY, float playerWidth, float playerHeight, float deltaTime);

    float getOffSetX() const { return offSetX; }
    float getOffSetY() const { return offSetY; }
private:
    float clamp(float value, float min, float max);
};
