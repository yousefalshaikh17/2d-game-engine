#include "Obstacle.h"

Obstacle::Obstacle(GameContext& context) : GameObject(context)
{
    transform->scale = sf::Vector2(100.0f, 100.0f);

    transform->position = sf::Vector2f(150, 150);

    BoxColliderComponent* collider = addComponent<BoxColliderComponent>();
}

Obstacle::~Obstacle() {

}