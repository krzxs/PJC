#include "entity.hpp"

#include "SFML/Graphics/RenderTarget.hpp"


Entity::Entity(sf::Texture &texture): animationController(AnimationController(&sprite, &texture)) {
    id = nextId++;
}

Entity::~Entity() = default;

auto Entity::getId() const -> unsigned long {
    return id;
}

template<typename T>
auto Entity::is() const -> bool {
    return dynamic_cast<T *>(this) != nullptr;
}

template<typename T>
auto Entity::as() -> T {
    return dynamic_cast<T *>(this);
}

auto Entity::setTexture(const sf::Texture &texture) -> void {
    sprite.setTexture(texture);
}

auto Entity::getPosition() const -> sf::Vector2f {
    return sprite.getPosition();
}

auto Entity::setPosition(const float x, const float y) -> void {
    sprite.setPosition(x, y);
}

auto Entity::render(sf::RenderTarget &target, bool hitBox) const -> void {
    target.draw(sprite);
}
