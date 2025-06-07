#pragma once
#include "../BaseComponent.h"
#include "../GameObject.h"
#include "../CollisionSystem.h"

#include <SFML/Graphics/RectangleShape.hpp>

class TransformComponent;

class BoxColliderComponent : public BaseComponent {
private:
    sf::RectangleShape shape;
public:
    BoxColliderComponent(GameObject* owner);
    virtual ~BoxColliderComponent();

    sf::FloatRect getBounds(); //TODO: Add const after debugging.
    void render(sf::RenderWindow& window) override;
};
