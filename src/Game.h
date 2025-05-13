#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

class Game {
private:
    // Delta Time handling
    sf::Clock updateClock;
    sf::Clock renderClock;
    float renderDeltaTime = 0;
    float updateDeltaTime = 0;

    // Window for game
    sf::RenderWindow window;

    // Temporary first object
    sf::CircleShape object;
    float movementMultiplier = 300;

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

    // Public run function
    void run();
};