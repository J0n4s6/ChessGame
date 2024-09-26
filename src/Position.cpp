#include "Position.hpp"

#include "Constants.hpp"

PixelPosition SlotPosition::ToPixelPosition() { return {this->x_axis * constants::SLOT_LEN, this->y_axis * constants::SLOT_LEN}; }

SlotPosition PixelPosition::ToSlotPosition() { return {this->x_axis / constants::SLOT_LEN, this->y_axis / constants::SLOT_LEN}; }