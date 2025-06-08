#pragma once

#include "../GameObject.h"
#include "../Components/BoxColliderComponent.h"
#include "../Components/RenderComponent.h"

class Obstacle : public GameObject {
private:
    
public:
    Obstacle(GameContext& context);
    virtual ~Obstacle();
};