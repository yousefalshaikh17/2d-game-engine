#include <SFML/Graphics.hpp>

class GameObject;

class BaseComponent {
public:
    BaseComponent(GameObject* owner) { setOwner(owner); };
    virtual ~BaseComponent() = default;
    virtual void update(float) {}
    virtual void fixedUpdate(float) {}
    virtual void interpolate(float) {}
    virtual void render(sf::RenderWindow&) {}

protected:
    GameObject* owner;
    void setOwner(GameObject* newOwner) { owner = newOwner; }
};
