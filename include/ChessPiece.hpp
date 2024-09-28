#pragma once
#include <raylib.h>

#include "Constants.hpp"
#include "Position.hpp"

namespace chess_game {
enum class Type { Pawn, Rook, Bishop, Knight, King, Queen };

enum class Side { White, Black };

class ChessPiece {
   public:
    ChessPiece(Type type, Side side, CellPosition position);
    ~ChessPiece();
    void DrawChessPiece();
    bool IsVec2InPiece(const Vector2& vec);
    void UpdatePositionWhenDragging(const Vector2& vec);
    CellPosition GetCellPosition() { return CellPosition(_position); }
    void SetCellPosition(CellPosition pos) { _position = pos.ToPixelPosition(); }
    bool CheckCollisionChessPiece(const ChessPiece& other);
    const Side GetSide() { return _side; }

   private:
    Type _type;
    Side _side;
    Vector2 _position;
    Texture2D _texture;
    Texture2D _LoadAndReiszeImage(const char* file_name);
    const CellPosition _GetCellPosition();
    const Rectangle _GetRectangle();
};
}  // namespace chess_game