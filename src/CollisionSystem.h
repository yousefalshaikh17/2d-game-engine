#pragma once
#include <vector>

class BoxColliderComponent;

class CollisionSystem {
public:
    void registerCollider(BoxColliderComponent* collider);
    void unregisterCollider(BoxColliderComponent* collider);
    void update();

private:
    std::vector<BoxColliderComponent*> colliders;
};
