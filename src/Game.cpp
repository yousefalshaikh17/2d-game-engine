#include "Game.h"

Game::Game() {
    initWindow();

    // Set up player
    {
        GameObject* player = new GameObject(context);

        sf::CircleShape* circle = new sf::CircleShape(0.5);
        circle->setFillColor(sf::Color::Green);
        player->transform.scale = sf::Vector2(100.0f, 100.0f);

        RenderComponent& render = player->addComponent<RenderComponent>();
        render.drawableEntity = new DrawableEntity(circle);
        BoxColliderComponent& collider = player->addComponent<BoxColliderComponent>();

        // Add control script
        player->addComponent<PlayerController>();

        objects.push_back(player);
    }

    // Set up obstacle
    {
        GameObject* obstacle = new GameObject(context);

        sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(1, 1));
        box->setFillColor(sf::Color::Red);
        RenderComponent& render = obstacle->addComponent<RenderComponent>();
        render.drawableEntity = new DrawableEntity(box);
        TransformComponent& transform = obstacle->transform;
        transform.scale = sf::Vector2(100.0f, 100.0f);
        transform.position = sf::Vector2f(150, 150);
        BoxColliderComponent collider = obstacle->addComponent<BoxColliderComponent>();

        objects.push_back(obstacle);
    }
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
    auto view = context.getComponentRegistry().view<TransformComponent>();
    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        transform.previousPosition = transform.position;
        transform.previousRotation = transform.rotation;
        transform.previousScale = transform.scale;
    }

    context.getScriptManager().fixedUpdate(deltaTime);

    // TODO refactor collision system
    context.getCollisionSystem().update(context.getComponentRegistry());
}

void Game::preRender(float alpha) {
    
}

void Game::update(float deltaTime) {
    context.getScriptManager().update(deltaTime);
}


void Game::render() {
    // The window is like a canvas
    window.clear();
    
    auto view = context.getComponentRegistry().view<RenderComponent, TransformComponent>();
    for (auto entity : view) {
        auto [transform, renderComponent] = view.get<TransformComponent, RenderComponent>(entity);

        DrawableEntity* drawableEntity = renderComponent.drawableEntity;

        if (drawableEntity == nullptr)
            continue;

        drawableEntity->setPosition(transform.position);
        drawableEntity->setRotation(sf::degrees(transform.rotation));
        drawableEntity->setScale(transform.scale);

        window.draw(*drawableEntity);
    }

    if (context.getCollisionSystem().visualizeColliders)
    {
        // @TODO: Render collider visualization
        auto view = context.getComponentRegistry().view<BoxColliderComponent>();
        for (auto entity : view) {
            BoxColliderComponent& collider = view.get<BoxColliderComponent>(entity);
            window.draw(collider.shape);
        }
    }

    // Display backbuffer
    window.display();
}

void Game::gameLoop() {
    float accumulator = 0.0f;
    const float dt = 1.0f / 60.0f;

    sf::Clock clock;
    float frameTime;
    float alpha;

    context.getScriptManager().start();

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
        update(frameTime);
        render();
    }
}

void Game::run() {
    gameLoop();
}
