#include "../../../headers/Entity/player/Player.hpp"
#include "../../../headers/Map/Map.hpp"
#include "../../../headers/Camera/Camera.hpp"

const float GRAVITY = 1000.0f; // Gravity constant
const float JUMP_FORCE = -500.0f; // Jump velocity

Player::Player(float windowWidth, float windowHeight) : Entity(Vec2(windowWidth / 2.0f, windowHeight - 50.0f))
{
    playerRect = { pos.x, pos.y, playerWidth, playerHeight }; // Initialize player rectangle
    GROUND_Y = windowHeight - playerHeight;
}

void Player::render(SDL_Renderer* renderer)
{
    render(renderer, nullptr); // Call the render function with no camera
}

void Player::render(SDL_Renderer* renderer, Camera* camera)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color to black 
    playerRect.x = pos.x + camera->getOffSetX(); // Update player rectangle position
    playerRect.y = pos.y + camera->getOffSetY(); // Update player rectangle position
    SDL_RenderFillRect(renderer, &playerRect); // Draw the player rectangle
}

Player::~Player() // Destructor
{

}

void Player::update(float deltaTime)
{
    update(deltaTime, nullptr); // Call the update function with no camera
}

void Player::update(float deltaTime, Camera* camera)
{
    if (isMovingLeft)
    {
        pos.x -= playerSpeed * deltaTime; // Move left
    }

    if (isMovingRight)
    {
        pos.x += playerSpeed * deltaTime; // Move right
    }

    if (pos.x < MAP_MIN_X)
    {
        pos.x = MAP_MIN_X; // Prevent going out of bounds
    }

    if (pos.x > MAP_MAX_X - playerWidth)
    {
        pos.x = MAP_MAX_X - playerWidth; // Prevent going out of bounds
    }

    if (!isOnGround) // If the player is not on the ground
    {
        vel.y += GRAVITY * deltaTime; // Apply gravity
        pos.y += vel.y * deltaTime; // Update vertical position
        
        if (vel.y > 0 && pos.y >= GROUND_Y) // If the player hits the ground
        {
            pos.y = GROUND_Y; // Set position to ground level
            vel.y = 0; // Reset vertical velocity
            isOnGround = true; // Set on ground flag
        }
    }

    playerRect.x = pos.x + camera->getOffSetX(); // Update player rectangle position
    playerRect.y = pos.y + camera->getOffSetX(); // Update player rectangle position
}

void Player::moveLeft(float deltaTime) // Move the player left
{
    isMovingLeft = true; // Set the moving left flag
}

void Player::moveRight(float deltaTime) // Move the player right
{
    isMovingRight = true; // Set the moving right flag
}

void Player::jump() // Make the player jump
{
    if (isOnGround) // Check if the player is on the ground 
    {
        vel.y = JUMP_FORCE; // Set the vertical velocity to jump force
        isOnGround = false; // Set the on ground flag to false
    }
}

void Player::setMovingLeft(bool movingLeft) // Set the moving left flag
{
    isMovingLeft = movingLeft; // Set the moving left flag
}

void Player::setMovingRight(bool movingRight) // Set the moving right flag
{
    isMovingRight = movingRight; // Set the moving right flag
}
