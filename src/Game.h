#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include "GameObject.h"
#include "Player.h"

class Game {
private:
    // Delta Time handling
    sf::Clock updateClock;
    sf::Clock renderClock;
    float renderDeltaTime = 0;
    float updateDeltaTime = 0;

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
    float getRenderDeltaTime() const;
    float getUpdateDeltaTime() const;

private:
    void initWindow();
    void update();
    void render();
    void gameLoop();
};