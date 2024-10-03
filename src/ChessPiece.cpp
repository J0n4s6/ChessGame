#include "ChessPiece.hpp"

#include <iostream>

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

const CellPosition ChessPiece::_GetCellPosition() { return CellPosition(_position); }

void ChessPiece::DrawChessPiece() { DrawTexture(_texture, _position.x, _position.y, WHITE); }

void ChessPiece::UpdatePositionWhenDragging(const Vector2& vec) { _position = {vec.x - consts::CELL_LEN / 2.0f, vec.y - consts::CELL_LEN / 2.0f}; };

bool ChessPiece::CheckCollisionChessPiece(const ChessPiece& other) { return _GetCellPosition() == CellPosition(other._position); }

bool ChessPiece::IsAbleToMove(CellPosition src_pos, CellPosition dst_pos) {
    if (dst_pos.IsOutOfBounds()) {
        return false;
    }
    /**
     * 1. Start with standard movements
     *  1.1. Pawn - done
     *  1.2. Rook - done
     *  1.3. Knight - done
     *  1.4. Bishop - done
     *  1.5. Queen - done
     *  1.6. King - done
     * 2. Then add special clauses:
     *  2.1. pawn start - done
     *  2.2. pawn eating
     *  2.2. pawn en-passent
     *  2.3. pawn upgrade (start by queen default) - done
     *  2.4. king short and long castle
     * 3. What about line of sight? <- for rook and bishop, the others are composed of them!)
     **/
    switch (_type) {
        case Type::Pawn:
            return _PawnMovement(src_pos, dst_pos);
        case Type::Rook:
            return _RookMovement(src_pos, dst_pos);
        case Type::Knight:
            return _KnightMovement(src_pos, dst_pos);
        case Type::Bishop:
            return _BishopMovement(src_pos, dst_pos);
        case Type::Queen:
            return _QueenMovement(src_pos, dst_pos);
        case Type::King:
            return _KingMovement(src_pos, dst_pos);
    }
    return false;
}

bool ChessPiece::_PawnMovement(CellPosition src_pos, CellPosition dst_pos) {
    if (src_pos.x != dst_pos.x) {
        return false;
    }
    switch (_side) {
        case Side::White:
            if (src_pos.y == 6) {
                return dst_pos.y == 5 || dst_pos.y == 4;
            } else {
                bool can_move = src_pos.y == dst_pos.y + 1;
                if (can_move && dst_pos.y == 0) {
                    UnloadTexture(_texture);
                    _type = Type::Queen;
                    _texture = _LoadAndReiszeImage(consts::WHITE_QUEEN);
                }
                return can_move;
            }
        case Side::Black:
            if (src_pos.y == 1) {
                return dst_pos.y == 2 || dst_pos.y == 3;
            } else {
                bool can_move = src_pos.y == dst_pos.y - 1;
                if (can_move && dst_pos.y == 7) {
                    UnloadTexture(_texture);
                    _type = Type::Queen;
                    _texture = _LoadAndReiszeImage(consts::BLACK_QUEEN);
                }
                return can_move;
            }
    }
    return false;
}

bool ChessPiece::_RookMovement(CellPosition src_pos, CellPosition dst_pos) {
    if (src_pos.x == dst_pos.x || src_pos.y == dst_pos.y) {
        return true;
    }
    return false;
}

bool ChessPiece::_BishopMovement(CellPosition src_pos, CellPosition dst_pos) {
    if (smath::abs(src_pos.y - dst_pos.y) == smath::abs(src_pos.x - dst_pos.x)) {
        return true;
    }
    return false;
}

bool ChessPiece::_QueenMovement(CellPosition src_pos, CellPosition dst_pos) { return _RookMovement(src_pos, dst_pos) || _BishopMovement(src_pos, dst_pos); }

bool ChessPiece::_KingMovement(CellPosition src_pos, CellPosition dst_pos) {
    return _ChebyshevDistance(src_pos, dst_pos) == 1 && _QueenMovement(src_pos, dst_pos);
}
bool ChessPiece::_KnightMovement(CellPosition src_pos, CellPosition dst_pos) {
    return _ChebyshevDistance(src_pos, dst_pos) == 2 && !_QueenMovement(src_pos, dst_pos);
}
}  // namespace chess_game