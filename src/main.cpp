#include <raylib.h>

#include "ChessGame.hpp"

int main(void) {
    InitWindow(chess_game::consts::SCREEN_LEN, chess_game::consts::SCREEN_LEN, "ChessGame");
    SetTargetFPS(60);
    std::unique_ptr<chess_game::ChessGame> chess_game = std::make_unique<chess_game::ChessGame>();
    while (!WindowShouldClose()) {
        chess_game->UpdateGame();
        chess_game->DrawGame();
    }
    chess_game = nullptr;
    CloseWindow();
    return 0;
}