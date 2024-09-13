#include <iostream>

#include "ChessBoard.hpp"
#include "raylib.h"

int main(void) {
    std::cout << "Hello, World!\n";
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    const int CON_WIDTH = 900;
    const int CON_HEIGHT = 900;
    InitWindow(CON_WIDTH, CON_HEIGHT, "ChessGame");
    SetTargetFPS(60);
    ChessBoard chess_board(CON_WIDTH, CON_HEIGHT);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        chess_board.DrawCheckBoard();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}