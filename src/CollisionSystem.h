#pragma once
#include "Components.h"
#include <entt/entt.hpp>
#include <vector>
#include <algorithm>

class BoxColliderComponent;

class CollisionSystem {
public:
    static bool visualizeColliders;

    void update(entt::registry& registry);
    void resolveCollision(BoxColliderComponent& a, TransformComponent& ta,
                          BoxColliderComponent& b, TransformComponent& tb);
};
