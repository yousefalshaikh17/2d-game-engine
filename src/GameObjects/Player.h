#pragma once

#include <SFML/Graphics.hpp>
#include "../GameObject.h"

class Player : public GameObject {
private:
    sf::CircleShape circle;
    float movementMultiplier = 300;
    sf::Vector2f velocity;
public:
    Player();
    virtual ~Player();
    void fixedUpdate(float deltaTime) override;
    void preRender(float alpha) override;
    void render(sf::RenderWindow& window) override;
};