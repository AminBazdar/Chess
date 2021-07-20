#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP
#include "cell.hpp"
#include <array>

class ChessBoard
{
public:
    ChessBoard(const ChessBoard &) = delete;     // delete copy constructor (because of singleton)
    void operator=(const ChessBoard &) = delete; // delete operator= (because of singleton)
    
    static ChessBoard &make_chess_board();       // a static function that can creat and return only one object of ChessBoard class (singleton method)
    void movePiece(std::string);                 // a function that enter a move after validation it

private:
    ChessBoard();                             // private constructor
    std::array<std::array<Cell, 8>, 8> cells; //a 2D array of Cell for 64 cells of chess board
};

#endif // CHESSBOARD_HPP
