#pragma once
#include "Components.h"
#include <entt/entt.hpp>
#include <vector>
#include <algorithm>

class BoxColliderComponent;
class GameContext;

class CollisionSystem {
public:
    static bool visualizeColliders;

    CollisionSystem(GameContext& context);

    void update(entt::registry& registry);
    void resolveCollision(BoxColliderComponent& a, TransformComponent& ta,
                          BoxColliderComponent& b, TransformComponent& tb);

private:
    GameContext& context;
};
