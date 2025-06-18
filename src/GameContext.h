#pragma once
#include "CollisionSystem.h"
#include "ScriptManager.h"
#include <entt/entt.hpp>

class GameContext {
public:
    GameContext();

    CollisionSystem& getCollisionSystem();
    entt::registry& getComponentRegistry();
    ScriptManager& getScriptManager();


private:
    entt::registry componentRegistry;
    CollisionSystem collisionSystem;
    ScriptManager scriptManager;
};
