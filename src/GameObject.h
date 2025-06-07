#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Components/TransformComponent.h"
#include "GameContext.h"

class GameObject {
protected:
    std::vector<BaseComponent*> components;
    GameContext& context;
public:
    TransformComponent* transform;

    GameObject(GameContext& context);
    virtual ~GameObject();
    virtual void fixedUpdate(float deltaTime);
    virtual void preRender(float alpha);
    virtual void render(sf::RenderWindow& window);

    virtual void onCollide(BoxColliderComponent& other);

    GameContext& getContext();

    // Component handling
    template<typename T>
    T* addComponent() {
        static_assert(std::is_base_of<BaseComponent, T>::value, "T must be derived from Component");
        
        T* existing = getComponent<T>();
        if (existing != nullptr) {
            std::cerr << "Warning: Component of type " << typeid(T).name() << " already exists. Returning existing component." << std::endl;
            return existing;
        }

        BaseComponent* component = new T(this);
        components.push_back(component);
        return static_cast<T*>(component);
    }

    template<typename T>
    T* getComponent() {
        for (BaseComponent* comp : components)
            if (T* casted = dynamic_cast<T*>(comp))
                return casted;

        return nullptr;
    }

    template<typename T>
    std::vector<T*> getComponents() {
        std::vector<T*> results;
        for (BaseComponent* comp : components)
            if (T* casted = dynamic_cast<T*>(comp))
                results.push_back(casted);
        return results;
    }

};