#pragma once
#include "CollisionSystem.h"
#include <entt/entt.hpp>

class GameContext {
public:
    CollisionSystem& getCollisionSystem();
    entt::registry& getComponentRegistry();

private:
    entt::registry componentRegistry;
    CollisionSystem collisionSystem;
    // Add other systems here later
};
