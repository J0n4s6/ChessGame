#pragma once
#include <raylib.h>

#include <ScreenDimensions.hpp>

enum class Type { Pawn, Rook, Bishop, Knight, King, Queen };

struct Position {
    int x_axis;
    int y_axis;
};

class ChessPiece {
   public:
    ChessPiece(Type type, Position position);
    void DrawChessPiece();

   private:
    Type _type;
    Position _position;
    Image _image;
    Texture2D _texture;
};