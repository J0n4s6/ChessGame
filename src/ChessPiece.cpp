#include "ChessPiece.hpp"

#include <iostream>
#include <stdexcept>

ChessPiece::ChessPiece(Type type, Position position) : _type(type), _position(position) {
    switch (_type) {
        case Type::Pawn:
            _image = LoadImage("media/images/white-pawn.png");
            // ImageResize(&_image, constants::SLOT_LEN, constants::SLOT_LEN);
            break;
        default:
            break;
    }
    if (_image.data == nullptr) {
        std::cerr << "Failed to load image for chess piece";
    }
    _texture = LoadTextureFromImage(_image);
}
void ChessPiece::DrawChessPiece() { DrawTexture(_texture, _position.x_axis, _position.y_axis, RED); }