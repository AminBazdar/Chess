cmake_minimum_required(VERSION 3.0)
project(AP)
set(CMAKE_CXX_STANDARD 11)
add_executable(exe 
src/main.cpp
src/chessman.cpp
src/cell.cpp
src/ChessBoard.cpp
src/player.cpp
src/Knight.cpp
src/Pawn.cpp
src/King.cpp
src/Queen.cpp
src/Bishop.cpp
src/Rook.cpp
src/game.cpp)
include_directories(include)