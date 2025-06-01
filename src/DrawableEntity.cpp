#include "DrawableEntity.h"

DrawableEntity::DrawableEntity(sf::Drawable* drawable): m_drawable(drawable) {

}

DrawableEntity::~DrawableEntity() {
    delete m_drawable;
    m_drawable = nullptr;
}

void DrawableEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    if (m_drawable)
        target.draw(*m_drawable, states);
}
