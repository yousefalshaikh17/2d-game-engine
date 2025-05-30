#include "Game.h"

#include <iostream>
#include <atomic>

Game::Game() {
    initWindow();
    Player* player = new Player();
    objects.push_back(player);
}

Game::~Game() {
    // Clean up all GameObject pointers
    for (GameObject* object : objects)
        delete object;
    objects.clear();
}

void Game::initWindow() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Instance", sf::State::Windowed, settings);
    window.setFramerateLimit(144);
}

void Game::handleEvents() {
    while (windowEvent = window.pollEvent()) {
        if (windowEvent->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::fixedUpdate(float deltaTime) {
    for (GameObject* object : objects)
        object->fixedUpdate(deltaTime);
}

void Game::preRender(float alpha) {
    for (GameObject* object : objects)
        object->preRender(alpha);
}


void Game::render() {
    // The window is like a canvas
    window.clear();
    
    for (GameObject* object : objects)
        object->render(window);

    // Display backbuffer
    window.display();
}

void Game::gameLoop() {
    float accumulator = 0.0f;
    const float dt = 1.0f / 60.0f;

    sf::Clock clock;
    float frameTime;
    float alpha;

    while (window.isOpen()) {
        frameTime = clock.restart().asSeconds();
        accumulator += frameTime;

        handleEvents();

        while (accumulator >= dt) {
            fixedUpdate(dt);
            accumulator -= dt;
        }

        alpha = accumulator / dt;

        preRender(alpha);
        render();
    }
}

void Game::run() {
    gameLoop();
}
