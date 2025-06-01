#pragma once
#include <SFML/Graphics.hpp>


class DrawableEntity : public sf::Drawable, public sf::Transformable {
public:
    DrawableEntity(sf::Drawable* drawable);
    ~DrawableEntity() override;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Drawable* m_drawable;
};