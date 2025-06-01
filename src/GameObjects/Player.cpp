#include "Player.h"

Player::Player() {
    sf::CircleShape* circle = new sf::CircleShape(50.0f);
    circle->setFillColor(sf::Color::Green);

    RenderComponent* render = addComponent<RenderComponent>();
    render->drawableEntity = new DrawableEntity(circle);
}

Player::~Player() {
    
}

void Player::fixedUpdate(float deltaTime) {
    GameObject::fixedUpdate(deltaTime);

    velocity = sf::Vector2f(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x += 1;

    // Account for user pressing multiple axis buttons
    if (velocity.x != 0  && velocity.y != 0)
        velocity = velocity.normalized();

    velocity = movementMultiplier * velocity;
    transform->position += velocity * deltaTime;
}