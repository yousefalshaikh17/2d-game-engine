#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject {
private:
    sf::CircleShape circle;
    float movementMultiplier = 300;
    sf::Vector2f velocity;
    sf::Vector2f previousPosition;
    sf::Vector2f currentPosition;
    sf::Vector2f interpolatedPosition;
public:
    Player();
    virtual ~Player();
    void fixedUpdate(float deltaTime);
    void preRender(float alpha);
    void render(sf::RenderWindow& window);
};