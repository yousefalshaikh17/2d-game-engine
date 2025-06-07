#pragma once

#include "../GameObject.h"
#include "../Components/BoxColliderComponent.h"

class Obstacle : public GameObject {
private:
    
public:
    Obstacle(GameContext& context);
    virtual ~Obstacle();
};