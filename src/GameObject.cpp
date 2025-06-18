#include "GameObject.h"

GameObject::GameObject(GameContext& context)
    : context(context),
    entityHandle(context.getComponentRegistry().create()),
    transform(addComponent<TransformComponent>()) // bind reference here
{

}

GameObject::~GameObject() {
    auto& registry = context.getComponentRegistry();
    if (!registry.valid(entityHandle))
        return;

    ScriptManager& manager = context.getScriptManager();
    for (ScriptComponent* script : manager.getGameObjectScripts(*this)) {
        manager.unregisterScript(script);
    }

    registry.destroy(entityHandle);
    entityHandle = entt::null;
}