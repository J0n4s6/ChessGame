#include "UpgradeWindow.hpp"

#include <iostream>

namespace chess_game {
UpgradeWindow::UpgradeWindow(std::function<void(Type)> choice_callback) : _choice_callback(choice_callback) {
    _rook_pos = {_window_background.x + consts::UPGRADE_WINDOW_PIECES_LEN / 3, _window_background.y + consts::UPGRADE_WINDOW_PIECES_LEN / 3};
    _rook_texture = _LoadAndReiszeImage(consts::WHITE_ROOK);
    _bishop_pos = {_window_background.x + consts::UPGRADE_WINDOW_PIECES_LEN / 3, _window_background.y + 5 * consts::UPGRADE_WINDOW_PIECES_LEN / 3};
    _bishop_texture = _LoadAndReiszeImage(consts::WHITE_BISHOP);
    _knight_pos = {_window_background.x + 5 * consts::UPGRADE_WINDOW_PIECES_LEN / 3, _window_background.y + consts::UPGRADE_WINDOW_PIECES_LEN / 3};
    _knight_texture = _LoadAndReiszeImage(consts::WHITE_KNIGHT);
    _queen_pos = {_window_background.x + 5 * consts::UPGRADE_WINDOW_PIECES_LEN / 3, _window_background.y + 5 * consts::UPGRADE_WINDOW_PIECES_LEN / 3};
    _queen_texture = _LoadAndReiszeImage(consts::WHITE_QUEEN);
}  // namespace chess_game

UpgradeWindow::~UpgradeWindow() {
    UnloadTexture(_rook_texture);
    UnloadTexture(_bishop_texture);
    UnloadTexture(_knight_texture);
    UnloadTexture(_queen_texture);
    _choice_callback(Type::Knight);  // TODO add choosing of type via mouse click collision
}

void UpgradeWindow::DrawUpgradeWindow() {
    DrawRectangleRounded(_window_background, _window_background_roundness, _window_background_segments, BEIGE);
    DrawRectangleRoundedLinesEx(_window_background, _window_background_roundness, _window_background_roundness, _window_background_line_thickness, BLACK);

    DrawTexture(_rook_texture, _rook_pos.x, _rook_pos.y, WHITE);
    DrawTexture(_bishop_texture, _bishop_pos.x, _bishop_pos.y, WHITE);
    DrawTexture(_knight_texture, _knight_pos.x, _knight_pos.y, WHITE);
    DrawTexture(_queen_texture, _queen_pos.x, _queen_pos.y, WHITE);
}

Texture2D UpgradeWindow::_LoadAndReiszeImage(const char* file_name) {
    Image image;
    if (!FileExists(file_name)) std::cerr << TextFormat("Could not find %s", file_name) << std::endl;
    image = LoadImage(file_name);
    ImageResize(&image, consts::UPGRADE_WINDOW_PIECES_LEN, consts::UPGRADE_WINDOW_PIECES_LEN);
    if (image.data == nullptr) {
        std::cerr << "Failed to load image for chess piece" << std::endl;
    }
    Texture texture = LoadTextureFromImage(image);
    UnloadImage(image);
    return texture;
}
}  // namespace chess_game