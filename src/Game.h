#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include "GameObject.h"
#include "Player.h"

class Game {
private:
    // Window for game
    sf::RenderWindow window;

    // Game Objects
    std::vector<GameObject *> objects;

public:
    // Constructor
    Game();
    // Deconstructor
    ~Game();

    void run();

private:
    void initWindow();
    void fixedUpdate(float deltaTime);
    void preRender(float alpha);
    void render();
    void gameLoop();
};