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
    std::shared_ptr<ChessPiece> _moving_piece = nullptr;
    CellPosition _moving_piece_last_position = {0, 0};
    Side _current_turn = Side::White;

    static std::shared_ptr<ChessPiece> _GetPieceCollisionWithMouse(const Vector2& vec, const std::list<std::shared_ptr<ChessPiece>>& pieces);
    static std::optional<std::shared_ptr<ChessPiece>> _MovingPieceEats(const std::shared_ptr<ChessPiece>& moving_piece,
                                                                       const std::list<std::shared_ptr<ChessPiece>>& pieces);
    static void _ToggleTurn(Side& turn) { turn = turn == Side::White ? Side::Black : Side::White; };
    static bool _IsDestinationOccupiedByAlly(const std::shared_ptr<ChessPiece>& moving_piece, const std::list<std::shared_ptr<ChessPiece>>& pieces,
                                             CellPosition& destination);
    static bool _IsAbleToMoveThisWay(const std::shared_ptr<ChessPiece>& moving_piece, CellPosition& last_position, CellPosition& destination) { return true; }
};
}  // namespace chess_game