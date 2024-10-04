#pragma once

namespace chess_game {
namespace consts {
constexpr int SCREEN_LEN = 896;
constexpr int BOARD_DIM = 8;
static_assert(SCREEN_LEN % BOARD_DIM == 0);
constexpr int CELL_LEN = SCREEN_LEN / BOARD_DIM;
constexpr int UPGRADE_WINDOW_LEN = SCREEN_LEN / 2;
constexpr int UPGRADE_WINDOW_POS = (SCREEN_LEN - UPGRADE_WINDOW_LEN) / 2;
static_assert(UPGRADE_WINDOW_POS > 0);
constexpr int UPGRADE_WINDOW_PIECES_LEN = UPGRADE_WINDOW_LEN / 3;
constexpr char BLACK_BISHOP[] = "media/images/black-bishop.png";
constexpr char BLACK_KING[] = "media/images/black-king.png";
constexpr char BLACK_KNIGHT[] = "media/images/black-knight.png";
constexpr char BLACK_PAWN[] = "media/images/black-pawn.png";
constexpr char BLACK_QUEEN[] = "media/images/black-queen.png";
constexpr char BLACK_ROOK[] = "media/images/black-rook.png";
constexpr char WHITE_BISHOP[] = "media/images/white-bishop.png";
constexpr char WHITE_KING[] = "media/images/white-king.png";
constexpr char WHITE_KNIGHT[] = "media/images/white-knight.png";
constexpr char WHITE_PAWN[] = "media/images/white-pawn.png";
constexpr char WHITE_QUEEN[] = "media/images/white-queen.png";
constexpr char WHITE_ROOK[] = "media/images/white-rook.png";
}  // namespace consts
}  // namespace chess_game