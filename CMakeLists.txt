cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    EnTT
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.12.2  # or latest stable release
    GIT_SHALLOW ON
    SYSTEM
)
FetchContent_MakeAvailable(EnTT)



add_executable(main
    src/main.cpp
    src/Game.cpp
    src/CollisionSystem.cpp
    src/GameContext.cpp
    src/GameObject.cpp
    src/GameObjects/Player.cpp
    src/Components/TransformComponent.cpp
    src/Components/RenderComponent.cpp
    src/DrawableEntity.cpp
    src/Components/BoxColliderComponent.cpp
    src/GameObjects/Obstacle.cpp
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
target_link_libraries(main PRIVATE SFML::Graphics EnTT::EnTT)
