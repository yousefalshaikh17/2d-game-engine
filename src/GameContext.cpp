#include "GameContext.h"

GameContext::GameContext() : collisionSystem(*this)
{
	
}

CollisionSystem& GameContext::getCollisionSystem()
{
	return collisionSystem;
}

entt::registry& GameContext::getComponentRegistry()
{
	return componentRegistry;
}

ScriptManager& GameContext::getScriptManager()
{
	return scriptManager;
}
