#include "ChessBoard.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include <string>
#include <iostream>
#include <random>
using namespace std;


ChessBoard::ChessBoard()
{
    // set black pieces on board
    cells[0][0].set_piece(new Rook(Chessman::color_::Black));
    cells[0][1].set_piece(new Knight(Chessman::color_::Black));
    cells[0][2].set_piece(new Bishop(Chessman::color_::Black));
    cells[0][3].set_piece(new Queen(Chessman::color_::Black));
    cells[0][4].set_piece(new King(Chessman::color_::Black));
    cells[0][5].set_piece(new Bishop(Chessman::color_::Black));
    cells[0][6].set_piece(new Knight(Chessman::color_::Black));
    cells[0][7].set_piece(new Rook(Chessman::color_::Black));

    cells[1][0].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][1].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][2].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][3].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][4].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][5].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][6].set_piece(new Pawn(Chessman::color_::Black));
    cells[1][7].set_piece(new Pawn(Chessman::color_::Black));

    // set white pieces on board
    cells[7][0].set_piece(new Rook(Chessman::color_::White));
    cells[7][1].set_piece(new Knight(Chessman::color_::White));
    cells[7][2].set_piece(new Bishop(Chessman::color_::White));
    cells[7][3].set_piece(new Queen(Chessman::color_::White));
    cells[7][4].set_piece(new King(Chessman::color_::White));
    cells[7][5].set_piece(new Bishop(Chessman::color_::White));
    cells[7][6].set_piece(new Knight(Chessman::color_::White));
    cells[7][7].set_piece(new Rook(Chessman::color_::White));

    cells[6][0].set_piece(new Pawn(Chessman::color_::White));
    cells[6][1].set_piece(new Pawn(Chessman::color_::White));
    cells[6][2].set_piece(new Pawn(Chessman::color_::White));
    cells[6][3].set_piece(new Pawn(Chessman::color_::White));
    cells[6][4].set_piece(new Pawn(Chessman::color_::White));
    cells[6][5].set_piece(new Pawn(Chessman::color_::White));
    cells[6][6].set_piece(new Pawn(Chessman::color_::White));
    cells[6][7].set_piece(new Pawn(Chessman::color_::White));

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
            if (game_check(turn) != nullptr)
            {
                cells[x_first][y_first].set_piece(cells[x_second][y_second].get_piece()); // moves the piece
                cells[x_second][y_second].set_piece(nullptr);
                cout << "you're check!!!" << endl;
            }

            else
            {
                cells[x_second][y_second].get_piece()->has_moved();
                Check_last_move(move);
                if (turn == Chessman::color_::White) // changes the turn
                {
                    player[0].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[0].last_move = move;
                    turn = Chessman::color_::Black;
                }
                else
                {
                    player[1].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[1].last_move = move;
                    turn = Chessman::color_::White;
                }
            }
            break;

        case Chessman::Move_type::Attack:
        {
            Chessman *temp = cells[x_second][y_second].get_piece();
            char symbol = cells[x_second][y_second].get_piece()->get_symbol();
            cells[x_second][y_second].set_piece(cells[x_first][y_first].get_piece()); // moves the piece
            cells[x_first][y_first].set_piece(nullptr);

            if (game_check(turn) != nullptr)
            {
                cells[x_first][y_first].set_piece(cells[x_second][y_second].get_piece()); // moves the piece
                cells[x_second][y_second].set_piece(temp);
                cout << "you're check!!!" << endl;
            }
            else
            {
                player[turn == Chessman::color_::White ? 1 : 0].add_attacked_piece(temp); // add the attacked pice to the related vector
                cells[x_second][y_second].get_piece()->has_moved();
                Check_last_move(move);
                if (turn == Chessman::color_::White) // changes the turn
                {
                    player[0].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[0].add_positive_score(attack_score(symbol));
                    player[0].last_move = move;
                    turn = Chessman::color_::Black;
                }
                else
                {
                    player[1].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[1].add_positive_score(attack_score(symbol));
                    player[1].last_move = move;
                    turn = Chessman::color_::White;
                }
            }
        }
        break;

        case Chessman::Move_type::Castling:
            cells[x_second][y_second].set_piece(cells[x_first][y_first].get_piece()); // moves the piece
            cells[x_first][y_first].set_piece(nullptr);
            if (y_second > y_first)
            {
                cells[x_second][y_second-1].set_piece(cells[x_first][y_first+3].get_piece());
                cells[x_first][y_first+3].set_piece(nullptr);
            }
            else
            {
                cells[x_second][y_second+1].set_piece(cells[x_first][y_first-4].get_piece());
                cells[x_first][y_first-4].set_piece(nullptr);
            }

            if (game_check(turn) != nullptr)
            {
                cells[x_first][y_first].set_piece(cells[x_second][y_second].get_piece()); // moves the piece
                cells[x_second][y_second].set_piece(nullptr);
                if (y_second > y_first)
                {
                    cells[x_second][y_first+3].set_piece(cells[x_first][y_second-1].get_piece());
                    cells[x_first][y_second-1].set_piece(nullptr);
                }
                else
                {
                    cells[x_second][y_first-4].set_piece(cells[x_first][y_second+1].get_piece());
                    cells[x_first][y_second+1].set_piece(nullptr);
                }
                
                cout << "you're check!!!" << endl;
            }
            else
            {                
                cells[x_second][y_second].get_piece()->has_moved();
                y_second > y_first ? cells[x_second][y_second-1].get_piece()->has_moved() : cells[x_second][y_second+1].get_piece()->has_moved();
                if (turn == Chessman::color_::White) // changes the turn
                {
                    player[0].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[0].add_positive_score(y_second > y_first ? cells[x_first][y_second-1].get_piece()->move_score(x_second, y_second-1, cells) : cells[x_first][y_second+1].get_piece()->move_score(x_second, y_second+1, cells));
                    turn = Chessman::color_::Black;
                }
                else
                {

                    player[1].add_positive_score(cells[x_second][y_second].get_piece()->move_score(x_second, y_second, cells));
                    player[1].add_positive_score(y_second > y_first ? cells[x_first][y_second-1].get_piece()->move_score(x_second, y_second-1, cells) : cells[x_first][y_second+1].get_piece()->move_score(x_second, y_second+1, cells));
                    turn = Chessman::color_::White;
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

Chessman *ChessBoard::game_check(Chessman::color_ turn)
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
                        return cells[i][j].get_piece();
                    }
                }
            }
        }
    }
    return nullptr;
}

Score ChessBoard::attack_score(char symbol)
{
    Score score = 0;

    switch (symbol)
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

bool ChessBoard::checkmate(Chessman::color_ turn)
{
    cout << "checkmate checking" << endl;
    int king_x;
    int king_y;

    string temp_s;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j].get_piece() != nullptr)
            {
                if (cells[i][j].get_piece()->get_symbol() == 'K' && cells[i][j].get_piece()->get_color() == turn)
                {
                    temp_s = cells[i][j].get_cell_id();
                }
            }
        }
    }

    king_x = 8 - (temp_s[1] - 48);
    king_y = temp_s[0] - 65;

    cout << temp_s << "x: " << king_x << "  y: " << king_y << endl;

    if (king_x - 1 >= 0)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x - 1][king_y].get_piece();

            cells[king_x - 1][king_y].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x - 1][king_y].get_piece()); // moves the piece
                cells[king_x - 1][king_y].set_piece(temp);
                cout << "1" << endl;
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x - 1][king_y].get_piece()); // moves the piece
            cells[king_x - 1][king_y].set_piece(temp);
        }
    }
    if (king_x - 1 >= 0 && king_y - 1 >= 0)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y - 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x - 1][king_y - 1].get_piece();

            cells[king_x - 1][king_y - 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x - 1][king_y - 1].get_piece()); // moves the piece
                cells[king_x - 1][king_y - 1].set_piece(temp);
                cout << "2" << endl;
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x - 1][king_y - 1].get_piece()); // moves the piece
            cells[king_x - 1][king_y - 1].set_piece(temp);
        }
    }
    if (king_x - 1 >= 0 && king_y + 1 < 8)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y + 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x - 1][king_y + 1].get_piece();

            cells[king_x - 1][king_y + 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x - 1][king_y + 1].get_piece()); // moves the piece
                cells[king_x - 1][king_y + 1].set_piece(temp);
                cout << "3" << endl;
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x - 1][king_y + 1].get_piece()); // moves the piece
            cells[king_x - 1][king_y + 1].set_piece(temp);
        }
    }
    cout << "bad az ...." << endl;
    if (king_x + 1 < 8 && king_y + 1 < 8)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x + 1, king_y + 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x + 1][king_y + 1].get_piece();

            cells[king_x + 1][king_y + 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x + 1][king_y + 1].get_piece()); // moves the piece
                cells[king_x + 1][king_y + 1].set_piece(temp);
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x + 1][king_y + 1].get_piece()); // moves the piece
            cells[king_x + 1][king_y + 1].set_piece(temp);
        }
    }
    if (king_x + 1 < 8 && king_y - 1 < 8)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x + 1, king_y - 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x + 1][king_y - 1].get_piece();

            cells[king_x + 1][king_y - 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x + 1][king_y - 1].get_piece()); // moves the piece
                cells[king_x + 1][king_y - 1].set_piece(temp);
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x + 1][king_y - 1].get_piece()); // moves the piece
            cells[king_x + 1][king_y - 1].set_piece(temp);
        }
    }
    if (king_x + 1 < 8)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x + 1, king_y, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x + 1][king_y].get_piece();

            cells[king_x + 1][king_y].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x + 1][king_y].get_piece()); // moves the piece
                cells[king_x + 1][king_y].set_piece(temp);
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x + 1][king_y].get_piece()); // moves the piece
            cells[king_x + 1][king_y].set_piece(temp);
        }
    }
    if (king_y + 1 < 8)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x, king_y + 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x][king_y + 1].get_piece();

            cells[king_x][king_y + 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x][king_y + 1].get_piece()); // moves the piece
                cells[king_x][king_y + 1].set_piece(temp);
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x][king_y + 1].get_piece()); // moves the piece
            cells[king_x][king_y + 1].set_piece(temp);
        }
    }
    if (king_y - 1 >= 0)
    {
        if (cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x, king_y - 1, cells) == Chessman::Move_type::Empty || cells[king_x][king_y].get_piece()->cell_access(king_x, king_y, king_x - 1, king_y, cells) == Chessman::Move_type::Attack)
        {
            Chessman *temp = cells[king_x][king_y - 1].get_piece();

            cells[king_x][king_y - 1].set_piece(cells[king_x][king_y].get_piece()); // moves the piece
            cells[king_x][king_y].set_piece(nullptr);
            if (game_check(turn) == nullptr)
            {
                cells[king_x][king_y].set_piece(cells[king_x][king_y - 1].get_piece()); // moves the piece
                cells[king_x][king_y - 1].set_piece(temp);
                return false;
            }
            cells[king_x][king_y].set_piece(cells[king_x][king_y - 1].get_piece()); // moves the piece
            cells[king_x][king_y - 1].set_piece(temp);
        }
    }

    cout << "king move" << endl;
    string temp_s2 = game_check(turn)->get_position();

    int check_x = 8 - (temp_s2[1] - 48);
    int check_y = temp_s2[0] - 65;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cells[i][j].get_piece() != nullptr)
            {
                if (cells[i][j].get_piece()->get_color() == turn && cells[i][j].get_piece()->cell_access(i, j, check_x, check_y, cells) == Chessman::Move_type::Attack)
                {
                    Chessman *temp = cells[check_x][check_y].get_piece();

                    cells[check_x][check_y].set_piece(cells[i][j].get_piece()); // moves the piece
                    cells[i][j].set_piece(nullptr);
                    if (game_check(turn) == nullptr)
                    {
                        cells[i][j].set_piece(cells[check_x][check_y].get_piece()); // moves the piece
                        cells[check_x][check_y].set_piece(temp);
                        return false;
                    }
                    cells[i][j].set_piece(cells[check_x][check_y].get_piece()); // moves the piece
                    cells[check_x][check_y].set_piece(temp);
                }
            }
        }
    }
    cout << "attack move" << endl;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (cells[row][col].get_piece() != nullptr)
            {
                if (cells[row][col].get_piece()->get_color() == turn)
                {

                    if (check_y == king_y)
                    {
                        int k = (king_x > check_x ? 1 : -1);
                        int i = check_x + k;
                        if (i != king_x)
                        {
                            if (cells[row][col].get_piece()->cell_access(row, col, i, check_y, cells) == Chessman::Move_type::Empty)
                            {
                                cells[i][check_y].set_piece(cells[row][col].get_piece()); // moves the piece
                                cells[row][col].set_piece(nullptr);
                                if (game_check(turn) == nullptr)
                                {
                                    cells[row][col].set_piece(cells[i][check_y].get_piece()); // moves the piece
                                    cells[i][check_y].set_piece(nullptr);
                                    return false;
                                }
                                cells[row][col].set_piece(cells[i][check_y].get_piece()); // moves the piece
                                cells[i][check_y].set_piece(nullptr);
                            }
                        }
                    }
                    if (check_x == king_x)
                    {
                        int k = (king_y > check_y ? 1 : -1);
                        int i = check_y + k;
                        if (i != king_y)
                        {
                            if (cells[row][col].get_piece()->cell_access(row, col, check_x, i, cells) == Chessman::Move_type::Empty)
                            {
                                cells[check_x][i].set_piece(cells[row][col].get_piece()); // moves the piece
                                cells[row][col].set_piece(nullptr);
                                if (game_check(turn) == nullptr)
                                {
                                    cells[row][col].set_piece(cells[check_x][i].get_piece()); // moves the piece
                                    cells[check_x][i].set_piece(nullptr);
                                    return false;
                                }
                                cells[row][col].set_piece(cells[check_x][i].get_piece()); // moves the piece
                                cells[check_x][i].set_piece(nullptr);
                            }
                        }
                    }
                    if (abs(king_x - check_x) == abs(king_y - check_y))
                    {
                        int k = king_x > check_x ? 1 : -1;
                        int z = king_y > check_y ? 1 : -1;

                        int i = check_x + k;
                        int j = check_y + z;
                        if (i != king_x)
                        {
                            if (cells[row][col].get_piece()->cell_access(row, col, i, j, cells) == Chessman::Move_type::Empty)
                            {
                                cells[i][j].set_piece(cells[row][col].get_piece()); // moves the piece
                                cells[row][col].set_piece(nullptr);
                                if (game_check(turn) == nullptr)
                                {
                                    cells[row][col].set_piece(cells[i][j].get_piece()); // moves the piece
                                    cells[i][j].set_piece(nullptr);
                                    return false;
                                }
                                cells[row][col].set_piece(cells[i][j].get_piece()); // moves the piece
                                cells[i][j].set_piece(nullptr);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "block move" << endl;
    return true;
}

void ChessBoard::operator=(ChessBoard & last_board)
{
    player[0] = last_board.player[0];
    player[1] = last_board.player[1];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cells[i][j] = last_board.cells[i][j];
        }
    }
    turn = last_board.turn;
}

void ChessBoard::Check_last_move(std::string move)
{
    if (turn == Chessman::color_::White)
    {
        if (player[0].last_move[0] == move[0] && player[0].last_move.substr(1, 2) == move.substr(3, 2) && 
            player[0].last_move.substr(3, 2) == move.substr(1, 2))
        {
            player[0].add_negative_score(2);
        }
    }
    else
    {
        if (player[1].last_move[0] == move[0] && player[1].last_move.substr(1, 2) == move.substr(3, 2) && 
            player[1].last_move.substr(3, 2) == move.substr(1, 2))
        {
            player[1].add_negative_score(2);
        }
    }
}

string ChessBoard::random_move()
{
    default_random_engine Eng(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<unsigned int> Rand(0, 7);
    bool find = false;
    unsigned int row, col;
    string move = "";
    while (!find)
    {
        row = Rand(Eng);
        col = Rand(Eng);
        if (cells[row][col].get_piece() != nullptr && cells[row][col].get_piece()->get_color() == turn)
        {
            find = true;
            move += cells[row][col].get_piece()->get_symbol();
            move += cells[row][col].get_cell_id();
            move += cells[row][col].get_piece()->random_cell(row, col, cells);
        }
    }
    return move;
}
