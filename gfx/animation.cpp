#include "animation.hpp"

Animation::Animation(sf::Sprite *sprite, sf::Texture *texture, const float frameTime, const int firstFrameX,
                     const int firstFrameY,
                     const int framesLengthX, const int framesLengthY, const int width,
                     const int height) : sprite(sprite),
                                         texture(texture),
                                         timer(0), frameTime(frameTime),
                                         width(width),
                                         height(height),
                                         done(false) {
    sprite->setTexture(*texture, true);

    start = sf::IntRect(firstFrameX * width, firstFrameY * height, width, height);
    current = start;
    end = sf::IntRect((framesLengthX - 1) * width, (framesLengthY - 1) * height, width, height);

    sprite->setTextureRect(start);
}

auto Animation::isDone() const -> bool {
    return done;
}

auto Animation::play(const float &tickDuration) -> bool {
    timer += 100 * tickDuration;
    done = false;

    if (timer >= frameTime) {
        timer = 0;

        if (current != end) {
            current.left += width;
        } else {
            done = true;
            current = start;
        }

        sprite->setTextureRect(current);
    }

    return done;
}

auto Animation::reset() -> void {
    timer = frameTime;
    current = start;
}
