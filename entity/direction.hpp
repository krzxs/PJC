#ifndef DIRECTION_HPP
#define DIRECTION_HPP

enum HorizontalDirection {
    WEST = -1, UNKNOWN_HORIZONTAL, EAST
};

enum VerticalDirection {
    SOUTH = -1, UNKNOWN_VERTICAL, NORTH
};

class Direction {
public:
    Direction();

    Direction(int horizontal, int vertical);

    auto getHorizontal() const -> int;

    auto getVertical() const -> int;

    auto operator==(const Direction &direction) const -> bool;

private:
    HorizontalDirection x;
    VerticalDirection y;
};


#endif //DIRECTION_HPP
