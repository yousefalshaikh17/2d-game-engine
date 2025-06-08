#include "BoxColliderComponent.h"

BoxColliderComponent::BoxColliderComponent(GameObject* owner): BaseComponent(owner)
{
	owner->getContext().getCollisionSystem().registerCollider(this);
	TransformComponent* transform = owner->transform;

	shape.setSize(transform->scale);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(1);
}

BoxColliderComponent::~BoxColliderComponent()
{
	owner->getContext().getCollisionSystem().unregisterCollider(this);
}

sf::FloatRect BoxColliderComponent::getBounds()
{
	TransformComponent* transform = owner->transform;
	shape.setPosition(transform->position);
	return shape.getGlobalBounds();
}

void BoxColliderComponent::render(sf::RenderWindow& window)
{
	if (owner->getContext().getCollisionSystem().visualizeColliders)
	{
		getBounds();
		window.draw(shape);
	}
}