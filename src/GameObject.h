#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
private:
    
public:
    virtual ~GameObject();
    virtual void fixedUpdate(float deltaTime);
    virtual void preRender(float alpha);
    virtual void render(sf::RenderWindow& window);
};