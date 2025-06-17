#pragma once

#include <SFML/Graphics.hpp>
#include "../GameObject.h"
#include "../Components/RenderComponent.h"
#include "../Components/BoxColliderComponent.h"

class Player : public GameObject {
private:
    float movementMultiplier = 300;
    sf::Vector2f velocity;
public:
    Player(GameContext& context);
    virtual ~Player();
    void fixedUpdate(float deltaTime) override;
    void onCollide(BoxColliderComponent& other) override;
};