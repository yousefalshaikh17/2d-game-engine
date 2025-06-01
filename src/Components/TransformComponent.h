#pragma once
#include "../BaseComponent.h"
#include <SFML/Graphics.hpp>

class TransformComponent : public BaseComponent {
private:
    sf::Vector2f previousPosition;
    sf::Vector2f interpolatedPosition;
    float previousRotation = 0.f;
    float angleDifference = 0.0f;
    float interpolatedRotation = 0.f;
    sf::Vector2f previousScale = { 1.f, 1.f };
    sf::Vector2f interpolatedScale = { 1.f, 1.f };

    float static lerpAngle(float start, float end, float alpha);

public:
    TransformComponent(GameObject* owner);
    virtual ~TransformComponent();

    sf::Vector2f position = { 0.f, 0.f };
    float rotation = 0.f;
    sf::Vector2f scale = { 1.f, 1.f };

    void scaleBy(const sf::Vector2f& factor);
    void translateBy(const sf::Vector2f& offset);
    void rotateBy(float delta);

    void fixedUpdate(float deltaTime) override;
    void interpolate(float alpha) override;

    // Getters for interpolated transforms (for rendering)
    sf::Vector2f getInterpolatedPosition() const;
    float getInterpolatedRotation() const;
    sf::Vector2f getInterpolatedScale() const;
};
