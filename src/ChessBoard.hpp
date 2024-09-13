#include <array>

#include "raylib.h"

struct Slot {
    Rectangle rectangle;
    Color color;
};

class ChessBoard {
   private:
    static const size_t _board_dim = 8;
    std::array<std::array<Slot, _board_dim>, _board_dim> _board;

   public:
    ChessBoard(int width, int height);
    void DrawCheckBoard();
};