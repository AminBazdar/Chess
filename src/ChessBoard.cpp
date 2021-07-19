#include "ChessBoard.hpp"

ChessBoard & ChessBoard::make_chess_board()
{
    static ChessBoard board; // make a static object of the ChessBoard class (because of singleton) 
    return board; 
}

ChessBoard::ChessBoard()
{

}


