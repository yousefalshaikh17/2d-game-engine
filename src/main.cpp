#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

static sf::RenderWindow InitWindow()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    return sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Game Instance", sf::State::Windowed, settings);
}

int main()
{
    sf::RenderWindow window = InitWindow();
    window.setFramerateLimit(120);

    // Load scene
    auto circle = sf::CircleShape(50.0f);
    circle.setFillColor(sf::Color::Green);

    sf::Clock clock;

    float deltaTime = 0;
    float movementMultiplier = 300;
    std::optional<sf::Event> event;

    sf::CircleShape obj = circle;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        while (event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Input
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 1;

        // Updates
        obj.move(movement * deltaTime * movementMultiplier);

        // Render
        // The window is like a canvas
        window.clear();
        window.draw(obj);

        // Display backbuffer
        window.display();
    }
    

}