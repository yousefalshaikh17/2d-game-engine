#pragma once

#include <SFML/Graphics.hpp>
#include "DrawableEntity.h"

class GameObject;
struct TransformComponent;

struct BaseComponent
{
public:
    GameObject* gameObject;
    TransformComponent* transform;

    BaseComponent() = default;

    friend class GameObject;
protected:
    void setOwner(GameObject* gameObject);
};

struct TransformComponent : BaseComponent
{
private:

public:
    sf::Vector2f position = { 0.f, 0.f };
    float rotation = 0.f;
    sf::Vector2f scale = { 1.f, 1.f };

    sf::Vector2f previousPosition;
    float previousRotation = 0.f;
    sf::Vector2f previousScale = { 1.f, 1.f };

    TransformComponent() = default;
    TransformComponent(const TransformComponent&) = default;

    bool hasMoved() const {
        return position != previousPosition || rotation != previousRotation || scale != previousScale;
    }
};

struct RenderComponent : BaseComponent
{
    DrawableEntity* drawableEntity = nullptr;

    RenderComponent() = default;
    RenderComponent(const RenderComponent&) = default;
    ~RenderComponent() { delete drawableEntity; drawableEntity = nullptr; };
};

struct BoxColliderComponent : BaseComponent
{
private:
    sf::RectangleShape shape;

    friend class Game;
public:
    bool isTrigger = false;

    BoxColliderComponent() {
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(1);
    };
    BoxColliderComponent(const BoxColliderComponent&) = default;

    sf::FloatRect getBounds() {
        return shape.getGlobalBounds();
    }

    void updateTransform(TransformComponent& transform) {
        shape.setPosition(transform.position);
        shape.setRotation(sf::degrees(transform.rotation));
        shape.setSize(transform.scale);
    }
};

struct ScriptComponent : BaseComponent
{
    virtual void start() {};
    virtual void update(float deltaTime) {};
    virtual void fixedUpdate(float deltaTime) {};
    virtual void onCollide(BoxColliderComponent& other) {};
};