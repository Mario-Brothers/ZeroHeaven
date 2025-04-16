#pragma once

#include <SDL3/SDL.h>

class Player
{
public:
    Player(float windowWidth, float windowHeight); // Constructor
    ~Player(); // Destructor
   
    void renderPlayer(SDL_Renderer* renderer); // Render the player
    void update(float deltaTime); // Update the player

    void moveLeft(float deltaTime); // Move the player left
    void moveRight(float deltaTime); // Move the player right
    void jump(); // Make the player jump
    void setMovingLeft(bool movingLeft); // Set the moving left flag
    void setMovingRight(bool movingRight); // Set the moving right flag

private:
    float x = 0.0f, y = 0.0f; // Player position
    float velocityY = 0.0f; // Player vertical velocity
    float playerSpeed = 200.0f; // Player speed
    bool isOnGround = false; // Check if the player is on the ground
    bool isMovingLeft = false; // Check if the player is moving left
    bool isMovingRight = false; // Check if the player is moving right

    SDL_FRect playerRect; // Player rectangle
    float playerHeight = 50.0f; // Player height
    float playerWidth = 50.0f; // Player width
};
