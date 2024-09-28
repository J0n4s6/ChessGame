#include "ChessPiece.hpp"

#include <iostream>
#include <stdexcept>

namespace chess_game {
ChessPiece::ChessPiece(Type type, Side side, CellPosition position) : _type(type), _side(side), _position(position.ToPixelPosition()) {
    switch (_side) {
        case Side::White:
            switch (_type) {
                case Type::Bishop:
                    _texture = _LoadAndReiszeImage(consts::WHITE_BISHOP);
                    break;
                case Type::King:
                    _texture = _LoadAndReiszeImage(consts::WHITE_KING);
                    break;
                case Type::Knight:
                    _texture = _LoadAndReiszeImage(consts::WHITE_KNIGHT);
                    break;
                case Type::Pawn:
                    _texture = _LoadAndReiszeImage(consts::WHITE_PAWN);
                    break;
                case Type::Queen:
                    _texture = _LoadAndReiszeImage(consts::WHITE_QUEEN);
                    break;
                case Type::Rook:
                    _texture = _LoadAndReiszeImage(consts::WHITE_ROOK);
                    break;
            }
            break;

        case Side::Black:
            switch (_type) {
                case Type::Bishop:
                    _texture = _LoadAndReiszeImage(consts::BLACK_BISHOP);
                    break;
                case Type::King:
                    _texture = _LoadAndReiszeImage(consts::BLACK_KING);
                    break;
                case Type::Knight:
                    _texture = _LoadAndReiszeImage(consts::BLACK_KNIGHT);
                    break;
                case Type::Pawn:
                    _texture = _LoadAndReiszeImage(consts::BLACK_PAWN);
                    break;
                case Type::Queen:
                    _texture = _LoadAndReiszeImage(consts::BLACK_QUEEN);
                    break;
                case Type::Rook:
                    _texture = _LoadAndReiszeImage(consts::BLACK_ROOK);
                    break;
            }
    }
}

ChessPiece::~ChessPiece() { UnloadTexture(_texture); }

Texture2D ChessPiece::_LoadAndReiszeImage(const char* file_name) {
    Image image;
    if (!FileExists(file_name)) std::cerr << TextFormat("Could not find %s", file_name) << std::endl;
    image = LoadImage(file_name);
    ImageResize(&image, consts::CELL_LEN, consts::CELL_LEN);
    if (image.data == nullptr) {
        std::cerr << "Failed to load image for chess piece" << std::endl;
    }
    Texture texture = LoadTextureFromImage(image);
    UnloadImage(image);
    return texture;
}

const Rectangle ChessPiece::_GetRectangle() { return {_position.x, _position.y, static_cast<float>(consts::CELL_LEN), static_cast<float>(consts::CELL_LEN)}; }

const CellPosition ChessPiece::_GetCellPosition() {
    return {static_cast<int>(_position.x / consts::CELL_LEN), static_cast<int>(_position.y / consts::CELL_LEN)};
}

void ChessPiece::DrawChessPiece() { DrawTexture(_texture, _position.x, _position.y, WHITE); }

bool ChessPiece::IsVec2InPiece(const Vector2& vec) { return CheckCollisionPointRec(vec, _GetRectangle()); }

void ChessPiece::UpdatePositionWhenDragging(const Vector2& vec) { _position = {vec.x - consts::CELL_LEN / 2.0f, vec.y - consts::CELL_LEN / 2.0f}; };

bool ChessPiece::CheckCollisionChessPiece(const ChessPiece& other) { return _position.x == other._position.x && _position.y == other._position.y; }
}  // namespace chess_game