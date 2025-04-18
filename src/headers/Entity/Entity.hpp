#pragma once

#include <SDL3/SDL.h>
#include "../../headers/Structures/Structures.hpp"

class Entity
{
public:
    Vec2 pos, vel;

    bool isOnGround;

    Entity(const Vec2& position);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};
