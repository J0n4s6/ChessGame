#include "Position.hpp"

#include "Constants.hpp"

namespace chess_game {
CellPosition::CellPosition(const Vector2& vec) : x(vec.x / consts::CELL_LEN), y(vec.y / consts::CELL_LEN) {}

CellPosition::CellPosition(int x, int y) : x(x), y(y) {}

Vector2 CellPosition::ToPixelPosition() { return {static_cast<float>(this->x * consts::CELL_LEN), static_cast<float>(this->y * consts::CELL_LEN)}; }

bool CellPosition::IsOutOfBounds() { return (x < 0) || (y < 0) || (x > 7) || (y > 7); }
}  // namespace chess_game