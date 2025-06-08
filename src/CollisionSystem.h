#pragma once
#include <vector>

class BoxColliderComponent;

class CollisionSystem {
public:
    static bool visualizeColliders;

    void registerCollider(BoxColliderComponent* collider);
    void unregisterCollider(BoxColliderComponent* collider);
    void update();
    void resolveCollision(BoxColliderComponent* a, BoxColliderComponent* b);
private:
    std::vector<BoxColliderComponent*> colliders;
};
