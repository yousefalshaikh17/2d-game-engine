#pragma once
#include "Components.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

class ScriptManager {
private:
    std::unordered_map<GameObject*, std::vector<ScriptComponent*>> scriptMap;
    bool started = false;

public:
    void registerScript(ScriptComponent* script);
    void unregisterScript(ScriptComponent* script);

    void start();
    void update(float deltaTime);
    void fixedUpdate(float deltaTime);

    const std::vector<ScriptComponent*>& getGameObjectScripts(GameObject& object);
};
