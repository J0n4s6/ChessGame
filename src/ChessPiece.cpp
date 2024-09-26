#include "ChessPiece.hpp"

#include <filesystem>
#include <iostream>
#include <stdexcept>

ChessPiece::ChessPiece(Type type, SlotPosition position, Side side) : _type(type), _position(position.ToPixelPosition()), _side(side) {
    switch (_side) {
        case Side::White:
            switch (_type) {
                case Type::Bishop:
                    _texture = LoadAndReiszeImage(constants::WHITE_BISHOP);
                    break;
                case Type::King:
                    _texture = LoadAndReiszeImage(constants::WHITE_KING);
                    break;
                case Type::Knight:
                    _texture = LoadAndReiszeImage(constants::WHITE_KNIGHT);
                    break;
                case Type::Pawn:
                    _texture = LoadAndReiszeImage(constants::WHITE_PAWN);
                    break;
                case Type::Queen:
                    _texture = LoadAndReiszeImage(constants::WHITE_QUEEN);
                    break;
                case Type::Rook:
                    _texture = LoadAndReiszeImage(constants::WHITE_ROOK);
                    break;
            }
            break;

        case Side::Black:
            switch (_type) {
                case Type::Bishop:
                    _texture = LoadAndReiszeImage(constants::BLACK_BISHOP);
                    break;
                case Type::King:
                    _texture = LoadAndReiszeImage(constants::BLACK_KING);
                    break;
                case Type::Knight:
                    _texture = LoadAndReiszeImage(constants::BLACK_KNIGHT);
                    break;
                case Type::Pawn:
                    _texture = LoadAndReiszeImage(constants::BLACK_PAWN);
                    break;
                case Type::Queen:
                    _texture = LoadAndReiszeImage(constants::BLACK_QUEEN);
                    break;
                case Type::Rook:
                    _texture = LoadAndReiszeImage(constants::BLACK_ROOK);
                    break;
            }
    }
}

ChessPiece::~ChessPiece() { UnloadTexture(_texture); }

Texture2D ChessPiece::LoadAndReiszeImage(const char* file_name) {
    Image image;
    if (!std::filesystem::exists(file_name)) std::cerr << TextFormat("Could not find %s", file_name) << std::endl;
    image = LoadImage(file_name);
    ImageResize(&image, constants::SLOT_LEN, constants::SLOT_LEN);
    if (image.data == nullptr) {
        std::cerr << "Failed to load image for chess piece" << std::endl;
    }
    Texture texture = LoadTextureFromImage(image);
    UnloadImage(image);
    return texture;
}

void ChessPiece::DrawChessPiece() { DrawTexture(_texture, _position.y_axis, _position.x_axis, WHITE); }