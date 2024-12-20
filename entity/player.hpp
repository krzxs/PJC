#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "entity_living.hpp"


class Player : public EntityLiving {
public:
    Player(float x, float y, sf::Texture &texture);

    auto updateAnimation(const float &tickDuration) -> void;

    auto update(const float &tickDuration) -> void override;

private:
    auto initAnimations() -> void;
};


#endif //PLAYER_HPP
