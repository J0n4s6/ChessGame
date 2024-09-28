#pragma once
#include <iostream>
#include <list>
#include <memory>
#include <optional>

#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include "Constants.hpp"
#include "raylib.h"

namespace chess_game {
void MouseDebugPrints(void) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) std::cout << "Button Down. ";
    if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) std::cout << "Button Up. ";
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) std::cout << "Button Pressed.";
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) std::cout << "Button Released. ";
    std::cout << TextFormat("Mouse Position: (%d, %d)\n", GetMouseX(), GetMouseY());
}

std::list<std::shared_ptr<ChessPiece>> InitiatePieces() {
    std::list<std::shared_ptr<ChessPiece>> pieces;
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{0, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{1, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{2, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{3, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{4, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{5, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{6, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{7, 6}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::White, CellPosition{0, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::White, CellPosition{1, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::White, CellPosition{2, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, Side::White, CellPosition{3, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, Side::White, CellPosition{4, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::White, CellPosition{5, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::White, CellPosition{6, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::White, CellPosition{7, 7}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{0, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{1, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{2, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{3, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{4, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{5, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{6, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{7, 1}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::Black, CellPosition{0, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::Black, CellPosition{1, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::Black, CellPosition{2, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, Side::Black, CellPosition{3, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, Side::Black, CellPosition{4, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::Black, CellPosition{5, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::Black, CellPosition{6, 0}));
    pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::Black, CellPosition{7, 0}));
    return pieces;
}

std::shared_ptr<ChessPiece> GetPieceCollisionWithMouse(const Vector2& vec, const std::list<std::shared_ptr<ChessPiece>>& pieces) {
    for (auto& piece : pieces) {
        if (piece->IsVec2InPiece(vec)) {
            return piece;
        }
    }
    return nullptr;
}

std::optional<std::shared_ptr<ChessPiece>> MovingPieceEats(const std::shared_ptr<ChessPiece>& moving_piece,
                                                           const std::list<std::shared_ptr<ChessPiece>>& pieces) {
    for (auto& piece : pieces) {
        if (piece.get() != moving_piece.get() && piece->CheckCollisionChessPiece(*moving_piece.get())) {
            return piece;
        }
    }
    return {};
}
}  // namespace chess_game