#include "game.hpp"

#include "fmt/base.h"
#include "SFML/Graphics/Texture.hpp"

auto Game::initTextures() -> void {
    if (!textures["PLAYER_SHEET"].loadFromFile("../res/player/player_sheet.png")) {
        fmt::println("Failed to load player_sheet.png");
    }
}

Game::Game() : window(sf::RenderWindow(sf::VideoMode(1600, 900), "PJC", sf::Style::Titlebar | sf::Style::Close)),
               dt(0.f), fps(0.f), frameCount(0) {
    initTextures();

    player = new Player(0, 0, textures["PLAYER_SHEET"]);
}

Game::~Game() {
    delete player;
}

void Game::run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        updateDt();
        update();
        render();
    }
}

void Game::updateDt() {
    dt = timer.restart().asSeconds();
    timeSinceLastUpdate += dt;
}

auto Game::updatePlayerInput(const float &tickDuration) const -> void {
    int x = 0, y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x += 1;
    }
    if (const auto direction = Direction(x, y); player->getDirection() != direction) {
        player->setLastDirection(player->getDirection());
        player->setDirection(direction);
    }
    player->move(tickDuration);
}

void Game::update() {
    ++frameCount;
    if (fpsTimer.getElapsedTime().asSeconds() >= 1.f) {
        fps = frameCount / fpsTimer.restart().asSeconds();
        fmt::println("FPS: {}", fps);
        frameCount = 0;
    }

    while (timeSinceLastUpdate >= tickDuration) {
        updatePlayerInput(timeSinceLastUpdate);
        player->update(timeSinceLastUpdate);
        timeSinceLastUpdate -= tickDuration;
    }
}

void Game::render() {
    window.clear();
    player->render(window, false);
    window.display();
}
