#include "Player.h"

Player::Player() {
    circle = sf::CircleShape(50.0f);
    circle.setFillColor(sf::Color::Green);
}

Player::~Player() {
    
}

void Player::update(float deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 1;

    // Update player position
    circle.move(movement * deltaTime * movementMultiplier);
}

void Player::render(sf::RenderWindow& window, float deltaTime) {
    window.draw(circle);
}