#ifndef MOVEMENT_CONTROLLER_HPP
#define MOVEMENT_CONTROLLER_HPP
#include "direction.hpp"
#include "SFML/Graphics/Sprite.hpp"


enum State {
    IDLE = 0, RUN_UP, RUN_DOWN, RUN_LEFT, RUN_RIGHT
};

class MovementController {
public:
    MovementController(sf::Sprite &sprite, float acceleration, float deceleration, float maxVelocity);

    auto getVelocity() const -> sf::Vector2f;

    auto getMaxVelocity() const -> float;

    auto stopX() -> void;

    auto stopY() -> void;

    auto stop() -> void;

    auto getState(unsigned int state) const -> bool;

    auto move(Direction direction, const float &tickDuration) -> void;

    auto updateMovement(const float &tickDuration) -> void;

private:
    sf::Sprite &sprite;

    float acceleration, deceleration;
    float maxVelocity;
    sf::Vector2f velocity;
};


#endif //MOVEMENT_CONTROLLER_HPP
