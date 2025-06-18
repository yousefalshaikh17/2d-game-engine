#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Components.h"
#include "GameContext.h"

class GameObject {
protected:
    GameContext& context;
    entt::entity entityHandle{ entt::null };
public:
    TransformComponent& transform;

    GameObject(GameContext& context);
    virtual ~GameObject();

    // Component handling
    template<typename T>
    T& addComponent() {
        static_assert(std::is_base_of<BaseComponent, T>::value, "T must be derived from BaseComponent");

        if (hasComponent<T>()) {
            std::cerr << "Warning: Component of type " << typeid(T).name() << " already exists. Returning existing component." << std::endl;
            return getComponent<T>();
        }

        T& comp = context.getComponentRegistry().emplace<T>(entityHandle);
        comp.setOwner(this);

        if constexpr (std::is_base_of_v<ScriptComponent, T>) {
            context.getScriptManager().registerScript(&comp);
        }

        return comp;
    }

    template<typename T>
    T& getComponent() {
        return context.getComponentRegistry().get<T>(entityHandle);
    }

    template<typename T>
    bool hasComponent() {
        return context.getComponentRegistry().any_of<T>(entityHandle);
    }
};