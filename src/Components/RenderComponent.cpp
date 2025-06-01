#include "RenderComponent.h"

RenderComponent::RenderComponent(GameObject* owner) : BaseComponent(owner)
{
}

RenderComponent::~RenderComponent()
{
	delete drawableEntity;
	drawableEntity = nullptr;
}

void RenderComponent::interpolate(float alpha)
{
	if (!drawableEntity)
		return;

	TransformComponent* transform = owner->transform;
	if (transform) {
		drawableEntity->setPosition(transform->getInterpolatedPosition());
		drawableEntity->setRotation(sf::degrees(transform->getInterpolatedRotation()));
		drawableEntity->setScale(transform->getInterpolatedScale());
	}
}

void RenderComponent::render(sf::RenderWindow& window)
{
	if (!drawableEntity)
		return;

	window.draw(*drawableEntity);
}
