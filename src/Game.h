#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include "GameObject.h"
#include "CollisionSystem.h"
#include "GameContext.h"
#include <iostream>
#include <atomic>
#include "Components.h"

// Scripts
#include "Scripts/PlayerController.cpp"

class Game {
private:
    // Window for game
    sf::RenderWindow window;
    std::optional<sf::Event> windowEvent;

    // Game Objects
    std::vector<GameObject *> objects;

    // Game context
    GameContext context;

public:
    // Constructor
    Game();
    // Deconstructor
    ~Game();

    void run();

private:
    void initWindow();
    void handleEvents();
    void fixedUpdate(float deltaTime);
    void update(float deltaTime);
    void preRender(float alpha);
    void render();
    void gameLoop();
};