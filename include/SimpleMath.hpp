#pragma once

namespace chess_game {
namespace smath {
constexpr int abs(int a) { return a > 0 ? a : -a; }

constexpr int max(int a, int b) { return a > b ? a : b; }
}  // namespace smath
}  // namespace chess_game