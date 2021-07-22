#include "ChessBoard.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "chessman.hpp"
#include <string>
#include <iostream>
using namespace std;

ChessBoard &ChessBoard::make_chess_board()
{
    static ChessBoard board; // make a static object of the ChessBoard class (because of singleton)

    // set black pieces on board
    board.cells[0][0].set_piece(new Rook(Chessman::color_::Black));
    board.cells[0][1].set_piece(new Knight(Chessman::color_::Black));
    board.cells[0][2].set_piece(new Bishop(Chessman::color_::Black));
    board.cells[0][3].set_piece(new Queen(Chessman::color_::Black));
    board.cells[0][4].set_piece(new King(Chessman::color_::Black));
    board.cells[0][5].set_piece(new Bishop(Chessman::color_::Black));
    board.cells[0][6].set_piece(new Knight(Chessman::color_::Black));
    board.cells[0][7].set_piece(new Rook(Chessman::color_::Black));

    board.cells[1][0].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][1].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][2].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][3].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][4].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][5].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][6].set_piece(new Pawn(Chessman::color_::Black));
    board.cells[1][7].set_piece(new Pawn(Chessman::color_::Black));

    // set white pieces on board
    board.cells[7][0].set_piece(new Rook(Chessman::color_::White));
    board.cells[7][1].set_piece(new Knight(Chessman::color_::White));
    board.cells[7][2].set_piece(new Bishop(Chessman::color_::White));
    board.cells[7][3].set_piece(new Queen(Chessman::color_::White));
    board.cells[7][4].set_piece(new King(Chessman::color_::White));
    board.cells[7][5].set_piece(new Bishop(Chessman::color_::White));
    board.cells[7][6].set_piece(new Knight(Chessman::color_::White));
    board.cells[7][7].set_piece(new Rook(Chessman::color_::White));

    board.cells[6][0].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][1].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][2].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][3].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][4].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][5].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][6].set_piece(new Pawn(Chessman::color_::White));
    board.cells[6][7].set_piece(new Pawn(Chessman::color_::White));

    return board;
}

ChessBoard::ChessBoard() {} // constructor

ChessBoard::~ChessBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete cells[i][j].get_piece();
        }
    }
}

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

bool ChessBoard::is_attack(const int &x_destination, const int &y_destination)
{
    //no need to check colors (colors has checked in cell access)
    if (cells[x_destination][y_destination].is_fill())
    {
        return true;
    }

    return false;
}

Score ChessBoard::attack(const int &x, const int &y)
{
    Score score = 0;

    switch (cells[x][y].get_piece()->get_symbol())
    {
    case 'P':
        score += 3;
        break;

    case 'R':
    case 'H':
    case 'B':
        score += 8;
        break;

    case 'Q':
        score += 15;
        break;
    }

    return score;
}