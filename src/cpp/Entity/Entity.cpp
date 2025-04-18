#include "../../headers/Entity/Entity.hpp" 

Entity::Entity(const Vec2& position)
    : pos(position), vel(0.0f, 0.0f), isOnGround(false){}
