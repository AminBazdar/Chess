#include "ChessBoard.hpp"
#include "chessman.hpp"
#include <string>
#include <iostream>
using namespace std;

ChessBoard &ChessBoard::make_chess_board()
{
    static ChessBoard board; // make a static object of the ChessBoard class (because of singleton)
    return board;
}

ChessBoard::ChessBoard() {} // constructor

void ChessBoard::movePiece(string move)
{
    char piece_symb = move[0];        //the piece symb
    int x_first = 8 - (move[2] - 48); // calculate the cells array indexes that piece is in
    int y_first = move[1] - 65;

    int x_second = 8 - (move[4] - 48); // calculate the cells array index that piece wants to go
    int y_second = move[3] - 65;


    if ((cells[x_first][y_first].get_piece())->cell_access(x_first, y_first, x_second, y_second, cells))
    {
        cells[x_second][y_second].set_piece(cells[x_first][y_first].get_piece());
        cells[x_first][y_first].set_piece(nullptr);
    }
    else
    {
        // error marboote!!!!!!!!!!!
    }
}
