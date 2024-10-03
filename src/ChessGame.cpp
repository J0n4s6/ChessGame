#include "ChessGame.hpp"

namespace chess_game {
ChessGame::ChessGame() {
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{0, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{1, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{2, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{3, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{4, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{5, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{6, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::White, CellPosition{7, 6}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::White, CellPosition{0, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::White, CellPosition{1, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::White, CellPosition{2, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, Side::White, CellPosition{3, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, Side::White, CellPosition{4, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::White, CellPosition{5, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::White, CellPosition{6, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::White, CellPosition{7, 7}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{0, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{1, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{2, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{3, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{4, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{5, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{6, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Pawn, Side::Black, CellPosition{7, 1}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::Black, CellPosition{0, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::Black, CellPosition{1, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::Black, CellPosition{2, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Queen, Side::Black, CellPosition{3, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::King, Side::Black, CellPosition{4, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Bishop, Side::Black, CellPosition{5, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Knight, Side::Black, CellPosition{6, 0}));
    _pieces.emplace_back(std::make_shared<ChessPiece>(Type::Rook, Side::Black, CellPosition{7, 0}));
}

void ChessGame::UpdateGame() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        _moving_piece = _GetPieceOnCell(CellPosition(GetMousePosition()), _pieces);
        if (_moving_piece != nullptr) {
            _moving_piece_last_position = _moving_piece->GetCellPosition();
        }
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        if (_moving_piece != nullptr) {
            CellPosition moving_piece_destination = CellPosition(GetMousePosition());
            bool move_is_legal = true;
            move_is_legal &= _moving_piece->GetSide() == _current_turn;
            move_is_legal &= _IsDestinationOccupiedByAlly(_moving_piece, _pieces, moving_piece_destination);
            move_is_legal &= _moving_piece->IsAbleToMove(_moving_piece_last_position, moving_piece_destination);
            if (move_is_legal) {
                _moving_piece->SetCellPosition(moving_piece_destination);
                auto eaten_piece = _MovingPieceEats(_moving_piece, _pieces);
                if (eaten_piece.has_value()) {
                    _pieces.remove(eaten_piece.value());
                }
                _ToggleTurn(_current_turn);
            } else {
                _moving_piece->SetCellPosition(_moving_piece_last_position);
            }
            _moving_piece = nullptr;
        }
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (_moving_piece != nullptr) {
            _moving_piece->UpdatePositionWhenDragging(GetMousePosition());
        }
    }
}

void ChessGame::DrawGame() {
    BeginDrawing();
    _chess_board.DrawCheckBoard();
    for (auto& piece : _pieces) {
        piece->DrawChessPiece();
    }
    EndDrawing();
}

std::shared_ptr<ChessPiece> ChessGame::_GetPieceOnCell(CellPosition pos, const std::list<std::shared_ptr<ChessPiece>>& pieces) {
    for (auto& piece : pieces) {
        if (piece->GetCellPosition() == pos) {
            return piece;
        }
    }
    return nullptr;
}

std::optional<std::shared_ptr<ChessPiece>> ChessGame::_MovingPieceEats(const std::shared_ptr<ChessPiece>& moving_piece,
                                                                       const std::list<std::shared_ptr<ChessPiece>>& pieces) {
    for (auto& piece : pieces) {
        if (piece.get() != moving_piece.get() && piece->GetSide() != moving_piece->GetSide() && piece->CheckCollisionChessPiece(*moving_piece.get())) {
            return piece;
        }
    }
    return {};
}

bool ChessGame::_IsDestinationOccupiedByAlly(const std::shared_ptr<ChessPiece>& moving_piece, const std::list<std::shared_ptr<ChessPiece>>& pieces,
                                             CellPosition& destination) {
    for (auto& piece : pieces) {
        if (piece->GetSide() == moving_piece->GetSide()) {
            if (piece->GetCellPosition() == destination) {
                return false;
            }
        }
    }
    return true;
}
}  // namespace chess_game