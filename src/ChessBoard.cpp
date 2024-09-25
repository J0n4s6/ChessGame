#include "ChessBoard.hpp"

#include "raylib.h"

ChessBoard::ChessBoard() {
    for (auto i = 0; i < constants::BOARD_DIM; i++) {
        for (auto j = 0; j < constants::BOARD_DIM; j++) {
            _board[i][j].color = (i + j) % 2 ? WHITE : BLACK;
            _board[i][j].rectangle = {static_cast<float>(i * constants::SLOT_LEN), static_cast<float>(j * constants::SLOT_LEN), constants::SLOT_LEN,
                                      constants::SLOT_LEN};
        }
    }
}
void ChessBoard::DrawCheckBoard() {
    for (auto i = 0; i < constants::BOARD_DIM; i++) {
        for (auto j = 0; j < constants::BOARD_DIM; j++) {
            DrawRectangleRec(_board[i][j].rectangle, _board[i][j].color);
        }
    }
}