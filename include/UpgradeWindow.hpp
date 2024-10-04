#pragma once
#include <raylib.h>

#include <string>

#include "Constants.hpp"

namespace chess_game {
class UpgradeWindow {
   private:
    const Rectangle _window_background = {consts::UPGRADE_WINDOW_POS, consts::UPGRADE_WINDOW_POS, consts::UPGRADE_WINDOW_LEN, consts::UPGRADE_WINDOW_LEN};
    const float _window_background_roundness = 0.1;
    const int _window_background_segments = 10;
    const int _window_background_line_thickness = 3;

    // The following options will be in a 2x2 grid
    Vector2 _rook_pos;
    Texture2D _rook_texture;
    Vector2 _bishop_pos;
    Texture2D _bishop_texture;
    Vector2 _knight_pos;
    Texture2D _knight_texture;
    Vector2 _queen_pos;
    Texture2D _queen_texture;

   public:
    UpgradeWindow();
    ~UpgradeWindow();
    void DrawUpgradeWindow();
    Texture2D _LoadAndReiszeImage(const char* file_name);
};
}  // namespace chess_game