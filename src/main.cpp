#include <iostream>
#include <list>
#include <memory>

#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include "Constants.hpp"
#include "raylib.h"

void MouseDebugPrints(void) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) std::cout << "Button Down. ";
    if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) std::cout << "Button Up. ";
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) std::cout << "Button Pressed.";
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) std::cout << "Button Released. ";
    std::cout << TextFormat("Mouse Position: (%d, %d)\n", GetMouseX(), GetMouseY());
}

std::list<std::shared_ptr<ChessPiece>> InitiatePieces() {
    std::list<std::shared_ptr<ChessPiece>> pieces;
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{0, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{1, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{2, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{3, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{4, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{5, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{6, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{7, 6}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, SlotPosition{0, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, SlotPosition{1, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, SlotPosition{2, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, SlotPosition{3, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, SlotPosition{4, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, SlotPosition{5, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, SlotPosition{6, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, SlotPosition{7, 7}, Side::White));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{0, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{1, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{2, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{3, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{4, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{5, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{6, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, SlotPosition{7, 1}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, SlotPosition{0, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, SlotPosition{1, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, SlotPosition{2, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, SlotPosition{3, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, SlotPosition{4, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, SlotPosition{5, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, SlotPosition{6, 0}, Side::Black));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, SlotPosition{7, 0}, Side::Black));
    return pieces;
}

std::shared_ptr<ChessPiece> GetPieceCollisionWithMouse(const Vector2& vec, const std::list<std::shared_ptr<ChessPiece>>& pieces) {
    for (auto& piece : pieces) {
        if (piece->IsVec2InPiece(vec)) {
            std::cout << "Picked Piece!\n";
            return piece;
        }
    }
    return nullptr;
}

int main(void) {
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    ChessBoard chess_board;
    InitWindow(constants::SCREEN_LEN, constants::SCREEN_LEN,
               "ChessGame");  // NOTE this sets up the OpenGL context, so it must exist before creating any textures
    std::list<std::shared_ptr<ChessPiece>> pieces = InitiatePieces();
    std::shared_ptr<ChessPiece> moving_piece;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        chess_board.DrawCheckBoard();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            std::cout << "Searching for piece\n";
            moving_piece = GetPieceCollisionWithMouse(GetMousePosition(), pieces);
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            moving_piece = nullptr;
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if (moving_piece != nullptr) {
                moving_piece->UpdatePosition(GetMousePosition());
            }
        }

        for (auto& piece : pieces) {
            piece->DrawChessPiece();  // NOTE destructor clear the texture, so the pieces should not exist in the same scope as InitWindow and CloseWindow
        }

        // MouseDebugPrints();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}