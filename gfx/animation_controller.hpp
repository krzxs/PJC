#ifndef ANIMATION_CONTROLLER_HPP
#define ANIMATION_CONTROLLER_HPP
#include <map>
#include <string>

#include "animation.hpp"


class AnimationController {
public:
    AnimationController(sf::Sprite *sprite, sf::Texture *texture);

    ~AnimationController();

    auto isDone(const std::string &name) const -> bool;

    auto addAnimation(const std::string &name, float frameTime, int firstFrameX, int firstFrameY,
                      int framesLengthX, int framesLengthY, int width, int height) -> void;

    auto play(const std::string &name, const float &tickDuration) -> bool;

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
    std::map<std::string, Animation> animations;
    std::string lastAnimation;
};


#endif //ANIMATION_CONTROLLER_HPP
