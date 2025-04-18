#pragma once

#include <SDL3/SDL.h>
#include "../../../headers/Entity/Entity.hpp"

class Player : public Entity
{
public:
    Player(float windowWidth, float windowHeight); // Constructor
    ~Player(); // Destructor
   
    void render(SDL_Renderer* renderer) override; // Render the player
    void update(float deltaTime) override; // Update the player

    void moveLeft(float deltaTime); // Move the player left
    void moveRight(float deltaTime); // Move the player right
    void jump(); // Make the player jump
    void setMovingLeft(bool movingLeft); // Set the moving left flag
    void setMovingRight(bool movingRight); // Set the moving right flag

private:
    SDL_FRect playerRect; // Player rectangle
    float playerSpeed = 200.0f; // Player speed
    bool isMovingLeft = false; // Check if the player is moving left
    bool isMovingRight = false; // Check if the player is moving right

    float playerHeight = 50.0f; // Player height
    float playerWidth = 50.0f; // Player width
};
