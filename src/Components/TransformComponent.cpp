#include "TransformComponent.h"
#include <cmath>
#include <iostream>

float TransformComponent::lerpAngle(float start, float end, float alpha)
{
    float angleDifference = end - start;

    if (angleDifference > 180.f)
        angleDifference -= 360.f;
    else if (angleDifference < -180.f)
        angleDifference += 360.f;

    return start + angleDifference * alpha;
}

TransformComponent::TransformComponent(GameObject* owner): BaseComponent(owner)
{

}

TransformComponent::~TransformComponent()
{

}

void TransformComponent::scaleBy(const sf::Vector2f& factor)
{
    scale.x *= factor.x;
    scale.y *= factor.y;
}

void TransformComponent::translateBy(const sf::Vector2f& offset)
{
    position += offset;
}

void TransformComponent::rotateBy(float delta)
{
    rotation += delta;

    while (rotation >= 360.f)
        rotation -= 360.f;

    while (rotation < 0.f)
        rotation += 360.f;
}

void TransformComponent::fixedUpdate(float deltaTime)
{
    // Cache previous state before changes
    previousPosition = position;
    previousRotation = rotation;
    previousScale = scale;
}

void TransformComponent::interpolate(float alpha)
{
    interpolatedPosition = previousPosition + (position - previousPosition) * alpha;
    interpolatedRotation = lerpAngle(previousRotation, rotation, alpha);
    interpolatedScale = previousScale + (scale - previousScale) * alpha;
}

sf::Vector2f TransformComponent::getInterpolatedPosition() const
{
    return interpolatedPosition;
}

float TransformComponent::getInterpolatedRotation() const
{
    return interpolatedRotation;
}

sf::Vector2f TransformComponent::getInterpolatedScale() const
{
    return interpolatedScale;
}
