#include "ChessBoard.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"
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

ChessBoard::ChessBoard()
{
} // constructor

ChessBoard::~ChessBoard() // destructor that deletes the pieces that we allocated manually
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
    static Chessman::color_ turn = Chessman::color_::White; //show which player turn is

    char piece_symb = move[0];        //the piece symb
    int x_first = 8 - (move[2] - 48); // calculate the cells array indexes that piece is in
    int y_first = move[1] - 65;

    int x_second = 8 - (move[4] - 48); // calculate the cells array index that piece wants to go
    int y_second = move[3] - 65;

    if (turn == cells[x_first][y_first].get_piece()->get_color()) // Checks the player's turn
    {

        // validation of move
        switch ((cells[x_first][y_first].get_piece())->cell_access(x_first, y_first, x_second, y_second, cells))
        {
        case Chessman::Move_type::Empty:
            cells[x_second][y_second].set_piece(cells[x_first][y_first].get_piece()); // moves the piece
            cells[x_first][y_first].set_piece(nullptr);
            if (game_check(turn))
            {
                cells[x_first][y_first].set_piece(cells[x_second][y_second].get_piece()); // moves the piece
                cells[x_second][y_second].set_piece(nullptr);
                cout << "you're check!!!" << endl;
            }
            else
            {

                if (turn == Chessman::color_::White) // changes the turn
                {
                    turn = Chessman::color_::Black;
                }
                else
                {
                    turn = Chessman::color_::White;
                }
            }
            break;
        case Chessman::Move_type::Attack:
        {
            Chessman *temp = cells[x_second][y_second].get_piece();

            cells[x_second][y_second].set_piece(cells[x_first][y_first].get_piece()); // moves the piece
            cells[x_first][y_first].set_piece(nullptr);
            if (game_check(turn))
            {
                cells[x_first][y_first].set_piece(cells[x_second][y_second].get_piece()); // moves the piece
                cells[x_second][y_second].set_piece(temp);
                cout << "you're check!!!" << endl;
            }
            else
            {
                player[turn == Chessman::color_::White ? 1 : 0]->add_attacked_piece(temp); // add the attacked pice to the related vector

                if (turn == Chessman::color_::White) // changes the turn
                {
                    turn = Chessman::color_::Black;
                }
                else
                {
                    turn = Chessman::color_::White;
                }
            }
        }
        break;

        case Chessman::Move_type::Block:
            cout << "Error !!!" << endl;
            cout << "There is a piece on the way !!!!" << endl;
            break;

        case Chessman::Move_type::SameColor:
            cout << "Error !!!" << endl;
            cout << "Cannot attack the same color piece !!!!" << endl;
            break;

        case Chessman::Move_type::Invalid:
            cout << "Error !!!" << endl;
            cout << "Invalid move !!!!" << endl;
            break;
        }
    }
    else // wrong turn error
    {
        if (turn == Chessman::color_::White)
        {
            cout << "its White's turn !!!" << endl;
        }
        else
        {
            cout << "its Black's turn !!!" << endl;
        }
    }
}

bool ChessBoard::game_check(Chessman::color_ turn)
{
    int king_x;
    int king_y;

    string temp;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j].get_piece() != nullptr)
            {
                if (cells[i][j].get_piece()->get_symbol() == 'K' && cells[i][j].get_piece()->get_color() == turn)
                {
                    temp = cells[i][j].get_cell_id();
                }
            }
        }
    }
    
    king_x = 8 - (temp[1] - 48);
    king_y = temp[0] - 65;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j].get_piece() != nullptr)
            {
                if (cells[i][j].get_piece()->get_color() != turn)
                {
                    if (cells[i][j].get_piece()->cell_access(i, j, king_x, king_y, cells) == Chessman::Move_type::Attack)
                    {
                        return true;
                    }
                }
            }
        }
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