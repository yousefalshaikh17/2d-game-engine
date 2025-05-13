#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    
public:
    virtual ~GameObject();
    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow& window, float deltaTime);
};