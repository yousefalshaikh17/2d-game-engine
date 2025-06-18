#include "GameContext.h"

CollisionSystem& GameContext::getCollisionSystem()
{
	return collisionSystem;
}

entt::registry& GameContext::getComponentRegistry()
{
	return componentRegistry;
}
