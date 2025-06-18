#include "CollisionSystem.h"
#include <iostream>

bool CollisionSystem::visualizeColliders = false;

void CollisionSystem::update(entt::registry& registry) {
    auto view = registry.view<BoxColliderComponent, TransformComponent>();
    for (auto itA = view.begin(); itA != view.end(); ++itA) {
        entt::entity entityA = *itA;
        auto& collider0 = view.get<BoxColliderComponent>(entityA);
        auto& transform0 = view.get<TransformComponent>(entityA);
        collider0.updateTransform(transform0);


        for (auto itB = std::next(itA); itB != view.end(); ++itB) {
            entt::entity entityB = *itB;
            auto& collider1 = view.get<BoxColliderComponent>(entityB);
            auto& transform1 = view.get<TransformComponent>(entityB);
            collider1.updateTransform(transform1);

            if (collider0.getBounds().findIntersection(collider1.getBounds())) { // Check needs to be added later for game objects with multiple types of colliders
                /*a->getGameObject()->onCollide(*b);
                b->getGameObject()->onCollide(*a);*/
                
                if (!collider0.isTrigger && !collider1.isTrigger) {
                    resolveCollision(collider1, transform1, collider0, transform0); // Fix collision order.
                }
            }
        }
    }
}

void CollisionSystem::resolveCollision(BoxColliderComponent& a, TransformComponent& ta,
                                       BoxColliderComponent& b, TransformComponent& tb) {

    BoxColliderComponent* mover = nullptr;
    TransformComponent* moverTransform = nullptr;

    if (ta.hasMoved() && !tb.hasMoved()) {
        mover = &a;
        moverTransform = &ta;
    }
    else if (tb.hasMoved() && !ta.hasMoved()) {
        mover = &b;
        moverTransform = &tb;
    }
    else {
        mover = &a;
        moverTransform = &ta;
    }

    sf::FloatRect rectA = a.getBounds();
    sf::FloatRect rectB = b.getBounds();

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
