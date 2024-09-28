#include "Helpers.hpp"

int main(void) {
    std::cout << TextFormat("raylib version: %d.%d.%d\n", RAYLIB_VERSION_MAJOR, RAYLIB_VERSION_MINOR, RAYLIB_VERSION_PATCH);

    chess_game::ChessBoard chess_board;
    InitWindow(chess_game::consts::SCREEN_LEN, chess_game::consts::SCREEN_LEN,
               "ChessGame");  // NOTE this sets up the OpenGL context, so it must exist before creating any textures
    std::list<std::shared_ptr<chess_game::ChessPiece>> pieces = chess_game::InitiatePieces();
    std::shared_ptr<chess_game::ChessPiece> moving_piece;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        chess_board.DrawCheckBoard();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            moving_piece = GetPieceCollisionWithMouse(GetMousePosition(), pieces);
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            if (moving_piece != nullptr) {
                moving_piece->CorrectPosition(GetMousePosition());
                auto eaten_piece = MovingPieceEats(moving_piece, pieces);
                if (eaten_piece.has_value()) {
                    pieces.remove(eaten_piece.value());
                }
                moving_piece = nullptr;
            }
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if (moving_piece != nullptr) {
                moving_piece->UpdatePosition(GetMousePosition());
            }
        }

        for (auto& piece : pieces) {
            piece->DrawChessPiece();  // NOTE destructor clear the texture, so the pieces should not exist in the same scope as InitWindow and CloseWindow
        }

        // MouseDebugPrints();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}