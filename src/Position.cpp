#include "Position.hpp"

#include "Constants.hpp"

SlotPosition::SlotPosition(const Vector2& vec) : x_axis(vec.x / constants::SLOT_LEN), y_axis(vec.y / constants::SLOT_LEN) {}

SlotPosition::SlotPosition(int x, int y) : x_axis(x), y_axis(y) {}

Vector2 SlotPosition::ToPixelPosition() {
    return {static_cast<float>(this->x_axis * constants::SLOT_LEN), static_cast<float>(this->y_axis * constants::SLOT_LEN)};
}
