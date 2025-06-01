#pragma once

#include <SFML/Graphics.hpp>
#include "../GameObject.h"
#include "../Components/RenderComponent.h"

class Player : public GameObject {
private:
    float movementMultiplier = 300;
    sf::Vector2f velocity;
public:
    Player();
    virtual ~Player();
    void fixedUpdate(float deltaTime) override;
};