#pragma once
#include "../BaseComponent.h"
#include "../GameObject.h"
#include <SFML/Graphics.hpp>
#include "../DrawableEntity.h"


class TransformComponent;

class RenderComponent : public BaseComponent {
private:

public:
    DrawableEntity* drawableEntity = nullptr;

    RenderComponent(GameObject* owner);
    virtual ~RenderComponent();

    virtual void interpolate(float) override;
    void render(sf::RenderWindow& window) override;
};
