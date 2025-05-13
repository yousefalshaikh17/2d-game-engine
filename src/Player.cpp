#include "Player.h"

Player::Player() {
    circle = sf::CircleShape(50.0f);
    circle.setFillColor(sf::Color::Green);
}

Player::~Player() {
    
}

void Player::update(float deltaTime) {
    movementDirection = sf::Vector2f(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movementDirection.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movementDirection.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movementDirection.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movementDirection.x += 1;

    // Account for user pressing multiple axis buttons
    if (movementDirection.x != 0  && movementDirection.y != 0)
        movementDirection = movementDirection.normalized();

    // Update player position
    circle.move(movementDirection * deltaTime * movementMultiplier);
}

void Player::render(sf::RenderWindow& window, float deltaTime) {
    window.draw(circle);
}