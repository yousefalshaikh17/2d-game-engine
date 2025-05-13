#include "Game.h"

void Game::initWindow() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Instance", sf::State::Windowed, settings);
    window.setFramerateLimit(120);
}

void Game::update() {
    updateDeltaTime = updateClock.restart().asSeconds();

    // Input
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 1;

    // Updates
    object.move(movement * updateDeltaTime * movementMultiplier);
}

void Game::render() {
    renderDeltaTime = renderClock.restart().asSeconds();

    // The window is like a canvas
    window.clear();
    window.draw(object);

    // Display backbuffer
    window.display();
}

void Game::gameLoop() {
    std::optional<sf::Event> event;

    while (window.isOpen()) {
        while (event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
        }

        update();
        render();
    }
}

float Game::getRenderDeltaTime() const {
    return renderDeltaTime;
}

float Game::getUpdateDeltaTime() const {
    return updateDeltaTime;
}

Game::Game() {
    initWindow();

    // Load scene
    object = sf::CircleShape(50.0f);
    object.setFillColor(sf::Color::Green);
}

void Game::run() {
    gameLoop();
}
