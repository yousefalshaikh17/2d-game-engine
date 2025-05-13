#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

static float renderDeltaTime = 0;
static float updateDeltaTime = 0;
static float movementMultiplier = 300;

static sf::RenderWindow InitWindow()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    return sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Instance", sf::State::Windowed, settings);
}

static void Update(sf::CircleShape& obj)
{
    // Input
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 1;

    // Updates
    obj.move(movement * updateDeltaTime * movementMultiplier);
}

static void Render(sf::RenderWindow& window, sf::CircleShape& obj)
{
    // The window is like a canvas
    window.clear();
    window.draw(obj);

    // Display backbuffer
    window.display();
}

static void GameLoop(sf::RenderWindow& window, sf::CircleShape& obj)
{
    sf::Clock renderClock;
    sf::Clock updateClock;

    std::optional<sf::Event> event;

    while (window.isOpen())
    {
        while (event = window.pollEvent())
            if (event->is<sf::Event::Closed>())
                window.close();

        updateDeltaTime = updateClock.restart().asSeconds();
        Update(obj);

        renderDeltaTime = renderClock.restart().asSeconds();
        Render(window, obj);
    }
}

int main()
{
    sf::RenderWindow window = InitWindow();
    window.setFramerateLimit(120);

    // Load scene
    auto circle = sf::CircleShape(50.0f);
    circle.setFillColor(sf::Color::Green);

    GameLoop(window, circle);

    // Handle exit
}