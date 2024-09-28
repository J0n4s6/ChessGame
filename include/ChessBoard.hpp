#include <array>

#include "Constants.hpp"
#include "raylib.h"

namespace chess_game {
struct Cell {
    Rectangle rectangle;
    Color color;
};

class ChessBoard {
   private:
    std::array<std::array<Cell, consts::BOARD_DIM>, consts::BOARD_DIM> _board;

   public:
    ChessBoard();
    void DrawCheckBoard();
};
}  // namespace chess_game