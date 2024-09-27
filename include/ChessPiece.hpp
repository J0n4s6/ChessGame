#pragma once
#include <raylib.h>

#include "Constants.hpp"
#include "Position.hpp"

enum class Type { Pawn, Rook, Bishop, Knight, King, Queen };

enum class Side { White, Black };

class ChessPiece {
   public:
    ChessPiece(Type type, SlotPosition position, Side side);
    ~ChessPiece();
    void DrawChessPiece();
    bool IsVec2InPiece(const Vector2& vec);
    void UpdatePosition(const Vector2& vec);
    void CorrectPosition(const Vector2& vec);

   private:
    Type _type;
    Side _side;
    Vector2 _position;
    Texture2D _texture;
    Texture2D LoadAndReiszeImage(const char* file_name);
};