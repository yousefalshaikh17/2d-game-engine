#include "GameObject.h"

GameObject::GameObject()
{
    transform = addComponent<TransformComponent>();
}

GameObject::~GameObject() {
    for (BaseComponent* component : components)
        delete component;
    components.clear();
}

void GameObject::fixedUpdate(float deltaTime)
{
    for (BaseComponent* component : components)
        component->fixedUpdate(deltaTime);
}

void GameObject::preRender(float alpha) {
    for (BaseComponent* component : components)
        component->interpolate(alpha);
}

void GameObject::render(sf::RenderWindow& window) {
    for (BaseComponent* component : components)
        component->render(window);
}