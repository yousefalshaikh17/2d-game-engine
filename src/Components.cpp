#include "Components.h"
#include "GameObject.h"

void BaseComponent::setOwner(GameObject* gameObject)
{
	this->gameObject = gameObject;
	transform = &gameObject->transform;
}

