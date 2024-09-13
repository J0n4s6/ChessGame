#include "ChessBoard.hpp"

#include "raylib.h"

ChessBoard::ChessBoard(int width, int height) {
    float slot_width = static_cast<float>(width / _board_dim);
    float slot_height = static_cast<float>(height / _board_dim);
    for (auto i = 0; i < _board_dim; i++) {
        for (auto j = 0; j < _board_dim; j++) {
            _board[i][j].color = (i + j) % 2 ? WHITE : BLACK;
            _board[i][j].rectangle = {i * slot_width, j * slot_height, slot_width, slot_height};
        }
    }
}
void ChessBoard::DrawCheckBoard() {
    for (auto i = 0; i < _board_dim; i++) {
        for (auto j = 0; j < _board_dim; j++) {
            DrawRectangleRec(_board[i][j].rectangle, _board[i][j].color);
        }
    }
}