#ifndef GAME_HPP
#define GAME_HPP
#include <map>

#include "../entity/player.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"


class Game {
public:
    Game();

    ~Game();

    auto run() -> void;

    auto updateDt() -> void;

    auto updatePlayerInput(const float &tickDuration) const -> void;

    auto update() -> void;

    auto render() -> void;

private:
    float static inline tickRate = 128.f;
    float static inline tickDuration = 1.0f / tickRate;

    sf::RenderWindow window;
    sf::Event event;
    sf::Clock timer;
    float timeSinceLastUpdate;
    float dt;
    sf::Clock fpsTimer;
    float fps;
    int frameCount;
    std::map<std::string, sf::Texture> textures;

    Player *player;

    auto initTextures() -> void;
};


#endif //GAME_HPP
