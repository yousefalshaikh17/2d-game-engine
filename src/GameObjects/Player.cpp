#include "Player.h"

Player::Player(GameContext& context): GameObject(context)
{
    sf::CircleShape* circle = new sf::CircleShape(0.5);
    circle->setFillColor(sf::Color::Green);

    transform.scale = sf::Vector2(100.0f, 100.0f);

    RenderComponent& render = addComponent<RenderComponent>();
    render.drawableEntity = new DrawableEntity(circle);

    BoxColliderComponent& collider = addComponent<BoxColliderComponent>();
}

Player::~Player() {
    
}

void Player::fixedUpdate(float deltaTime) {
    velocity = sf::Vector2f(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x += 1;

    // Account for user pressing multiple axis buttons
    if (velocity.x != 0 && velocity.y != 0)
        velocity = velocity.normalized();

    velocity = movementMultiplier * velocity;
    transform.position += velocity * deltaTime;
}