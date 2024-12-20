#include "direction.hpp"

Direction::Direction(): x(UNKNOWN_HORIZONTAL), y(UNKNOWN_VERTICAL) {
}

Direction::Direction(int horizontal, int vertical): x(static_cast<HorizontalDirection>(horizontal)),
                                                    y(static_cast<VerticalDirection>(vertical)) {
}

auto Direction::getHorizontal() const -> int {
    return x;
}

auto Direction::getVertical() const -> int {
    return y;
}

auto Direction::operator==(const Direction &direction) const -> bool {
    return x == direction.getHorizontal() && y == direction.getVertical();
}
