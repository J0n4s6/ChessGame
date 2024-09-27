#pragma once
#include <raylib.h>

/**
 * \brief this saves the position of the chess piece according to an 8x8 grid
 * \example (0,0), (5,7), (3,4)
 */
struct SlotPosition {
    int x_axis;
    int y_axis;
    SlotPosition(int x, int y);
    SlotPosition(const Vector2& vec);
    Vector2 ToPixelPosition();
};