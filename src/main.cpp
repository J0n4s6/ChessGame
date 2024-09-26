#include <iostream>
#include <vector>

#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include "ScreenDimensions.hpp"
#include "raylib.h"

int main(void) {
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    ChessBoard chess_board;
    std::vector<ChessPiece> pieces;
    pieces.emplace_back(Type::Pawn, Position{constants::SLOT_LEN, constants::SLOT_LEN});
    InitWindow(constants::SCREEN_LEN, constants::SCREEN_LEN, "ChessGame");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        chess_board.DrawCheckBoard();
        for (auto& piece : pieces) {
            piece.DrawChessPiece();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}