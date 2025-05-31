#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject {
private:
    sf::CircleShape circle;
    float movementMultiplier = 300;
    sf::Vector2f movementDirection;
public:
    Player();
    virtual ~Player();
    void update(float deltaTime);
    void render(sf::RenderWindow& window, float deltaTime);
};