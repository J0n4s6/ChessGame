#pragma once
#include <raylib.h>

#include "Constants.hpp"
#include "Position.hpp"
#include "SimpleMath.hpp"

namespace chess_game {
enum class Type { Pawn, Rook, Bishop, Knight, King, Queen };

enum class Side { White, Black };

class ChessPiece {
   public:
    ChessPiece(Type type, Side side, CellPosition position);
    ~ChessPiece();
    void DrawChessPiece();
    void UpdatePositionWhenDragging(const Vector2& vec);
    CellPosition GetCellPosition() { return CellPosition(_position); }
    void SetCellPosition(CellPosition pos) { _position = pos.ToPixelPosition(); }
    bool CheckCollisionChessPiece(const ChessPiece& other);
    const Side GetSide() { return _side; }
    const Type GetType() { return _type; }
    bool IsAbleToMove(CellPosition src_pos, CellPosition dst_pos);

   private:
    Type _type;
    Side _side;
    Vector2 _position;
    Texture2D _texture;
    Texture2D _LoadAndReiszeImage(const char* file_name);
    const CellPosition _GetCellPosition();
    const Rectangle _GetRectangle();

    bool _PawnMovement(CellPosition src_pos, CellPosition dst_pos);
    bool _RookMovement(CellPosition src_pos, CellPosition dst_pos);
    bool _BishopMovement(CellPosition src_pos, CellPosition dst_pos);
    bool _QueenMovement(CellPosition src_pos, CellPosition dst_pos);
    bool _KingMovement(CellPosition src_pos, CellPosition dst_pos);
    bool _KnightMovement(CellPosition src_pos, CellPosition dst_pos);
    int _ChebyshevDistance(CellPosition r1, CellPosition r2) { return smath::max(smath::abs(r2.x - r1.x), smath::abs(r2.y - r1.y)); }
};
}  // namespace chess_game