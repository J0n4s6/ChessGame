#pragma once
#include <raylib.h>

#include <list>
#include <memory>
#include <optional>

#include "ChessBoard.hpp"
#include "ChessPiece.hpp"

namespace chess_game {
class ChessGame {
   public:
    ChessGame();
    void UpdateGame();
    void DrawGame();

   private:
    ChessBoard _chess_board;
    std::list<std::shared_ptr<ChessPiece>> _pieces;
    std::shared_ptr<ChessPiece> _moving_piece;

    static std::shared_ptr<ChessPiece> _GetPieceCollisionWithMouse(const Vector2& vec, const std::list<std::shared_ptr<ChessPiece>>& pieces);
    static std::optional<std::shared_ptr<ChessPiece>> _MovingPieceEats(const std::shared_ptr<ChessPiece>& moving_piece,
                                                                       const std::list<std::shared_ptr<ChessPiece>>& pieces);
};
}  // namespace chess_game