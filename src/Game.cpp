#include "Game.h"

Game::Game() {
    initWindow();
    Player* player = new Player();
    objects.push_back(player);
}

Game::~Game() {
    // Clean up all GameObject pointers
    for (GameObject* object : objects) {
        delete object;
        object = nullptr;
    }
    objects.clear();
}

void Game::initWindow() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Instance", sf::State::Windowed, settings);
    window.setFramerateLimit(120);
}

void Game::update() {
    updateDeltaTime = updateClock.restart().asSeconds();

    for (GameObject* object : objects)
        object->update(updateDeltaTime);
}

void Game::render() {
    renderDeltaTime = renderClock.restart().asSeconds();

    // The window is like a canvas
    window.clear();
    
    for (GameObject* object : objects)
        object->render(window, renderDeltaTime);

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

void Game::run() {
    gameLoop();
}
