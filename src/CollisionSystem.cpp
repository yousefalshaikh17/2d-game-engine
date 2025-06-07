#include "CollisionSystem.h"
#include "Components/BoxColliderComponent.h"

void CollisionSystem::registerCollider(BoxColliderComponent* collider) {
    colliders.push_back(collider);
}

void CollisionSystem::unregisterCollider(BoxColliderComponent* collider) {
    colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
}

void CollisionSystem::update() {
    for (size_t i = 0; i < colliders.size(); i++) {
        for (size_t j = i + 1; j < colliders.size(); j++) {
            BoxColliderComponent* a = colliders[i];
            BoxColliderComponent* b = colliders[j];
            if (a->getBounds().findIntersection(b->getBounds())) { // Check needs to be added later for game objects with multiple types of colliders
                a->getGameObject()->onCollide(*b);
                b->getGameObject()->onCollide(*a);
            }
        }
    }
}