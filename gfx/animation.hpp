#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include "SFML/Graphics/Sprite.hpp"


class Animation {
public:
    Animation(sf::Sprite *sprite, sf::Texture *texture, float frameTime, int firstFrameX, int firstFrameY,
              int framesLengthX, int framesLengthY, int width, int height);

    auto isDone() const -> bool;

    auto play(const float &tickDuration) -> bool;

    auto reset() -> void;

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
    float timer;
    float frameTime;
    int width, height;
    sf::IntRect start, current, end;
    bool done;
};


#endif //ANIMATION_HPP
