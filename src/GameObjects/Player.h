#pragma once

#include <SFML/Graphics.hpp>
#include "../GameObject.h"

class Player : public GameObject {
private:
    float movementMultiplier = 300;
    sf::Vector2f velocity;
    
public:
    Player(GameContext& context);
    virtual ~Player();

    void fixedUpdate(float deltaTime);
};