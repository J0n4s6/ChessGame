#include <array>

#include "Constants.hpp"
#include "raylib.h"

struct Slot {
    Rectangle rectangle;
    Color color;
};

class ChessBoard {
   private:
    std::array<std::array<Slot, constants::BOARD_DIM>, constants::BOARD_DIM> _board;

   public:
    ChessBoard();
    void DrawCheckBoard();
};