#include <iostream>

#include "ChessBoard.hpp"
#include "ScreenDimensions.hpp"
#include "raylib.h"

int main(void) {
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    InitWindow(constants::SCREEN_LEN, constants::SCREEN_LEN, "ChessGame");
    SetTargetFPS(60);
    ChessBoard chess_board;
    while (!WindowShouldClose()) {
        BeginDrawing();
        chess_board.DrawCheckBoard();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}