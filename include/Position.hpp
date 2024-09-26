#pragma once

struct PixelPosition;
struct SlotPosition;

/**
 * \brief this saves the position in pixels of the left-most up-most corner of the chess piece currently in play
 * \example (0,0), (112, 112), (448, 672)
 */
struct PixelPosition {
    int x_axis;
    int y_axis;
    SlotPosition ToSlotPosition();
};

/**
 * \brief this saves the position of the chess piece according to an 8x8 grid
 * \example (0,0), (5,7), (3,4)
 */
struct SlotPosition {
    int x_axis;
    int y_axis;
    PixelPosition ToPixelPosition();
};