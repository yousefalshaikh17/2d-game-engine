#pragma once
#include "CollisionSystem.h"

class GameContext {
public:
    CollisionSystem& getCollisionSystem();

private:
    CollisionSystem collisionSystem;
    // Add other systems here later
};
