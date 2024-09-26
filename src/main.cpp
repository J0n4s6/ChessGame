#include <iostream>
#include <list>

#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include "Constants.hpp"
#include "raylib.h"

std::list<ChessPiece> InitiatePieces() {
    std::list<ChessPiece> pieces;
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 0}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 1}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 2}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 3}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 4}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 5}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 6}, Side::White);
    pieces.emplace_back(Type::Pawn, SlotPosition{6, 7}, Side::White);
    pieces.emplace_back(Type::Rook, SlotPosition{7, 0}, Side::White);
    pieces.emplace_back(Type::Knight, SlotPosition{7, 1}, Side::White);
    pieces.emplace_back(Type::Bishop, SlotPosition{7, 2}, Side::White);
    pieces.emplace_back(Type::Queen, SlotPosition{7, 3}, Side::White);
    pieces.emplace_back(Type::King, SlotPosition{7, 4}, Side::White);
    pieces.emplace_back(Type::Bishop, SlotPosition{7, 5}, Side::White);
    pieces.emplace_back(Type::Knight, SlotPosition{7, 6}, Side::White);
    pieces.emplace_back(Type::Rook, SlotPosition{7, 7}, Side::White);

    pieces.emplace_back(Type::Pawn, SlotPosition{1, 0}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 1}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 2}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 3}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 4}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 5}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 6}, Side::Black);
    pieces.emplace_back(Type::Pawn, SlotPosition{1, 7}, Side::Black);
    pieces.emplace_back(Type::Rook, SlotPosition{0, 0}, Side::Black);
    pieces.emplace_back(Type::Knight, SlotPosition{0, 1}, Side::Black);
    pieces.emplace_back(Type::Bishop, SlotPosition{0, 2}, Side::Black);
    pieces.emplace_back(Type::Queen, SlotPosition{0, 3}, Side::Black);
    pieces.emplace_back(Type::King, SlotPosition{0, 4}, Side::Black);
    pieces.emplace_back(Type::Bishop, SlotPosition{0, 5}, Side::Black);
    pieces.emplace_back(Type::Knight, SlotPosition{0, 6}, Side::Black);
    pieces.emplace_back(Type::Rook, SlotPosition{0, 7}, Side::Black);
    return pieces;
}

int main(void) {
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    ChessBoard chess_board;
    InitWindow(constants::SCREEN_LEN, constants::SCREEN_LEN,
               "ChessGame");  // NOTE this sets up the OpenGL context, so it must exist before creating any textures
    std::list<ChessPiece> pieces = InitiatePieces();
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        chess_board.DrawCheckBoard();
        for (auto& piece : pieces) {
            piece.DrawChessPiece();  // NOTE destructor clear the texture, so the pieces should not exist in the same scope as InitWindow and CloseWindow
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}