#include "ChessBoard.hpp"

#include "raylib.h"

namespace chess_game {
ChessBoard::ChessBoard() {
    for (auto i = 0; i < consts::BOARD_DIM; i++) {
        for (auto j = 0; j < consts::BOARD_DIM; j++) {
            _board[i][j].color = (i + j) % 2 ? BROWN : BEIGE;
            _board[i][j].rectangle = {static_cast<float>(i * consts::CELL_LEN), static_cast<float>(j * consts::CELL_LEN), consts::CELL_LEN, consts::CELL_LEN};
        }
    }
}
void ChessBoard::DrawCheckBoard() {
    for (auto i = 0; i < consts::BOARD_DIM; i++) {
        for (auto j = 0; j < consts::BOARD_DIM; j++) {
            DrawRectangleRec(_board[i][j].rectangle, _board[i][j].color);
        }
    }
}
}  // namespace chess_game