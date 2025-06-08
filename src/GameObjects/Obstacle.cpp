#include "Obstacle.h"

Obstacle::Obstacle(GameContext& context) : GameObject(context)
{
    sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(1,1));
    box->setFillColor(sf::Color::Red);

    RenderComponent* render = addComponent<RenderComponent>();
    render->drawableEntity = new DrawableEntity(box);

    transform->scale = sf::Vector2(100.0f, 100.0f);

    transform->position = sf::Vector2f(150, 150);

    BoxColliderComponent* collider = addComponent<BoxColliderComponent>();
}

Obstacle::~Obstacle() {

}