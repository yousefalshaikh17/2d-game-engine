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

    // Private functions
    void initWindow();
    void update();
    void render();
    void gameLoop();

public:
    // Public functions
    float getRenderDeltaTime() const;
    float getUpdateDeltaTime() const;

    // Constructor
    Game();

    // Deconstructor
    ~Game();

    // Public run function
    void run();
};