#include "../Components.h"
#include <iostream>

struct PlayerController : ScriptComponent {

    float movementMultiplier = 300;
    sf::Vector2f velocity;

    void fixedUpdate(float deltaTime) {
        velocity = sf::Vector2f(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y += 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x += 1;

        // Account for user pressing multiple axis buttons
        if (velocity.x != 0 && velocity.y != 0)
            velocity = velocity.normalized();

        velocity = movementMultiplier * velocity;
        transform->position += velocity * deltaTime;
    }

    void onCollide(BoxColliderComponent& other) {
        std::cout << "Collide" << std::endl;
    }
};