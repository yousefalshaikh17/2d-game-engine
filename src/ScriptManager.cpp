#include "ScriptManager.h"

void ScriptManager::registerScript(ScriptComponent* script)
{
	scriptMap[script->gameObject].push_back(script);
	// Send start signal if it happened after start()
	if (started)
		script->start();
}

void ScriptManager::unregisterScript(ScriptComponent* script)
{
	auto& scripts = scriptMap[script->gameObject];
	scripts.erase(std::remove(scripts.begin(), scripts.end(), script), scripts.end());
	if (scripts.empty()) {
		scriptMap.erase(script->gameObject);
	}
}

void ScriptManager::start()
{
	if (started)
		return;

	for (auto& [go, scripts] : scriptMap)
		for (auto* script : scripts)
			script->start();

	started = true;
}

void ScriptManager::update(float deltaTime)
{
	for (auto& [go, scripts] : scriptMap)
		for (auto* script : scripts)
			script->update(deltaTime);
}

void ScriptManager::fixedUpdate(float deltaTime)
{
	for (auto& [go, scripts] : scriptMap)
		for (auto* script : scripts)
			script->fixedUpdate(deltaTime);
}

const std::vector<ScriptComponent*>& ScriptManager::getGameObjectScripts(GameObject& object)
{
	static std::vector<ScriptComponent*> empty;
	auto it = scriptMap.find(&object);
	return it != scriptMap.end() ? it->second : empty;
}
