#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>

#include "../gfx/animation_controller.hpp"


class Entity {
public:
    Entity(sf::Texture &texture);

    virtual ~Entity();

    auto getId() const -> unsigned long;

    template<typename T>
    auto is() const -> bool;

    template<typename T>
    auto as() -> T;

    auto setTexture(const sf::Texture &texture) -> void;

    //Movement
    auto getPosition() const -> sf::Vector2f;

    auto setPosition(float x, float y) -> void;

    //Update
    virtual auto update(const float &tickDuration) -> void = 0;

    virtual auto render(sf::RenderTarget &target, bool hitBox) const -> void;

private:
    static inline unsigned long nextId = 0;
    unsigned long id;

protected:
    sf::Sprite sprite;
    AnimationController animationController;
};


#endif //ENTITY_HPP
