#include "CollisionSystem.h"
#include "GameContext.h"
#include <iostream>

bool CollisionSystem::visualizeColliders = false;

CollisionSystem::CollisionSystem(GameContext& context) : context(context)
{

}

void CollisionSystem::update(entt::registry& registry) {
    auto view = registry.view<BoxColliderComponent, TransformComponent>();
    for (auto itA = view.begin(); itA != view.end(); ++itA) {
        entt::entity entityA = *itA;
        auto& colliderA = view.get<BoxColliderComponent>(entityA);
        auto& transformA = view.get<TransformComponent>(entityA);
        colliderA.updateTransform(transformA);


        for (auto itB = std::next(itA); itB != view.end(); ++itB) {
            entt::entity entityB = *itB;
            auto& colliderB = view.get<BoxColliderComponent>(entityB);
            auto& transformB = view.get<TransformComponent>(entityB);
            colliderB.updateTransform(transformB);

            if (colliderA.getBounds().findIntersection(colliderB.getBounds())) { // Check needs to be added later for game objects with multiple types of colliders

                // @TODO: This can be optimized by having a cache. Same apply to collider and transform.
                std::vector<ScriptComponent*> scriptsA = context.getScriptManager().getGameObjectScripts(*colliderA.gameObject);
                for (ScriptComponent* script : scriptsA) {
                    script->onCollide(colliderB);
                }

                std::vector<ScriptComponent*> scriptsB = context.getScriptManager().getGameObjectScripts(*colliderB.gameObject);
                for (ScriptComponent* script : scriptsB) {
                    script->onCollide(colliderA);
                }

                
                if (!colliderA.isTrigger && !colliderB.isTrigger) {
                    resolveCollision(colliderB, transformB, colliderA, transformA); // Fix collision order.
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
