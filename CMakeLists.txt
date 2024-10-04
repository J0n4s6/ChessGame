cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(ChessGame)

set(RAYLIB external/raylib)
add_subdirectory(${RAYLIB})

add_executable(ChessGame src/main.cpp src/ChessGame.cpp src/ChessBoard.cpp src/ChessPiece.cpp src/Position.cpp src/UpgradeWindow.cpp)
target_include_directories(ChessGame PRIVATE ${RAYLIB}/src include)
target_link_libraries(ChessGame PRIVATE raylib)
target_compile_options(ChessGame PRIVATE  -Wall -Werror)