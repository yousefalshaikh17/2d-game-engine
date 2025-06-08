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


                if (!a->isTrigger && !b->isTrigger) {
                    resolveCollision(a, b);
                }
            }
        }
    }
}

void CollisionSystem::resolveCollision(BoxColliderComponent* a, BoxColliderComponent* b) {
    TransformComponent* ta = a->getGameObject()->transform;
    TransformComponent* tb = b->getGameObject()->transform;

    BoxColliderComponent* mover = nullptr;
    TransformComponent* moverTransform = nullptr;

    if (ta->hasMoved() && !tb->hasMoved()) {
        mover = a;
        moverTransform = ta;
    }
    else if (tb->hasMoved() && !ta->hasMoved()) {
        mover = b;
        moverTransform = tb;
    }
    else {
        mover = a;
        moverTransform = ta;
    }

    sf::FloatRect rectA = a->getBounds();
    sf::FloatRect rectB = b->getBounds();

    auto optIntersection = rectA.findIntersection(rectB);
    if (!optIntersection) return;
    sf::FloatRect inter = *optIntersection;

    bool horizontal = inter.size.x < inter.size.y;
    float push = horizontal ? inter.size.x : inter.size.y;

    if (horizontal) {
        float centerAx = rectA.position.x + rectA.size.x / 2.f;
        float centerBx = rectB.position.x + rectB.size.x / 2.f;
        moverTransform->position.x += (centerAx > centerBx) ? push : -push;
    }
    else {
        float centerAy = rectA.position.y + rectA.size.y / 2.f;
        float centerBy = rectB.position.y + rectB.size.y / 2.f;
        moverTransform->position.y += (centerAy > centerBy) ? push : -push;
    }
}
