#include "player.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

auto Player::initAnimations() -> void {
    animationController.addAnimation("IDLE", 15, 0, 0, 4, 1, 48, 48);
    animationController.addAnimation("RUN_LEFT", 11, 0, 1, 8, 2, 48, 48);
    animationController.addAnimation("RUN_RIGHT", 11, 0, 2, 8, 3, 48, 48);
    animationController.addAnimation("RUN_UP", 11, 0, 3, 8, 4, 48, 48);
    animationController.addAnimation("RUN_DOWN", 11, 0, 4, 8, 5, 48, 48);
}

Player::Player(const float x, const float y, sf::Texture &texture): EntityLiving(
    texture, 100, Direction(WEST, UNKNOWN_VERTICAL), 4000.f, 3000.f, 300.f) {
    initAnimations();
    sprite.setScale(3.f, 3.f);

    setPosition(x, y);
}

auto Player::updateAnimation(const float &tickDuration) -> void {
    if (movementController.getState(IDLE)) {
        animationController.play("IDLE", tickDuration);
    } else if (movementController.getState(RUN_UP)) {
        animationController.play("RUN_UP", tickDuration);
    } else if (movementController.getState(RUN_DOWN)) {
        animationController.play("RUN_DOWN", tickDuration);
    } else if (movementController.getState(RUN_LEFT)) {
        animationController.play("RUN_LEFT", tickDuration);
    } else if (movementController.getState(RUN_RIGHT)) {
        animationController.play("RUN_RIGHT", tickDuration);
    }
}

auto Player::update(const float &tickDuration) -> void {
    movementController.updateMovement(tickDuration);
    updateAnimation(tickDuration);
}
