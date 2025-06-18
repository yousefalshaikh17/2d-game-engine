#include "GameObject.h"

GameObject::GameObject(GameContext& context)
    : context(context),
    entityHandle(context.getComponentRegistry().create()),
    transform(addComponent<TransformComponent>()) // bind reference here
{

}

GameObject::~GameObject() {
    
}