#pragma once
#include <raylib.h>

namespace chess_game {
/**
 * \brief this saves the position of the chess piece according to an 8x8 grid
 * \example (0,0), (5,7), (3,4)
 */
struct CellPosition {
    int x;
    int y;
    CellPosition(int x, int y);
    CellPosition(const Vector2& vec);
    Vector2 ToPixelPosition();
    bool IsOutOfBounds();
    bool operator==(const CellPosition& other) const;
};
}  // namespace chess_game