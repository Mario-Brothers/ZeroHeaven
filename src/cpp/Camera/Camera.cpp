#include "../../headers/Camera/Camera.hpp"

#include <algorithm>

float Camera::clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void Camera::update(float playerX, float playerY, float playerWidth, float playerHeight, float deltaTime)
{
    float targetOffSetX = (screenWidth / 2.0f) - (playerX + playerWidth / 2.0f);
    float targetOffSetY = (screenHeight / 2.0f) - (playerY + playerHeight / 2.0f);

    float clampedX = clamp(targetOffSetX, std::min(0.0f, screenWidth - mapWidth), 0.0f);
    float clampedY = clamp(targetOffSetY, std::min(0.0f, screenHeight - mapHeight), 0.0f);

    float smoothing = 5.0f; // im większa, tym szybsze przesuwanie

    offSetX += (clampedX - offSetX) * deltaTime * smoothing;
    offSetY += (clampedY - offSetY) * deltaTime * smoothing;
}

