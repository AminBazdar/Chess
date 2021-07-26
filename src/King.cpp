#include "King.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>
#include <map>
#include <random>
#include <iterator>

King::King(Chessman::color_ color) : Chessman(color, 'K') {}

Chessman::Move_type King::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (is_castling(x_first, y_first, x_second, y_second, board))
    {
        return Move_type::Castling;
    }

    if ((abs(x_second - x_first) == 1 && (abs(y_second - y_first) == 1 || abs(y_second - y_first) == 0)) || (abs(x_second - x_first) == 0 && abs(y_second - y_first) == 1))
    {
        if (board[x_second][y_second].is_fill())
        {
            if (board[x_second][y_second].get_piece()->get_color() != get_color())
            {
                return Chessman::Move_type::Attack;
            }
            else
            {
                return Chessman::Move_type::SameColor;
            }
        }
        return Chessman::Move_type::Empty;
    }
    return Chessman::Move_type::Invalid;
}

bool King::is_castling(const int& x_first, const int& y_first, const int& x_second, const int& y_second, std::array<std::array<Cell, 8>, 8> & board)
{
    if (x_first - x_second == 0 && (abs(y_second - y_first) == 2) && (!board[x_first][y_first].get_piece()->is_moved()))
    {
        if (y_second - y_first == 2 && board[x_first][y_first+1].get_piece() == nullptr && board[x_first][y_first+2].get_piece() == nullptr)
        {
            for (size_t i = 0; i < 8; i++)
            {
                for (size_t j = 0; j < 8 ; j++)
                {
                    if (board[i][j].get_piece() != nullptr)
                    {
                        if (board[i][j].get_piece()->get_color() != get_color() && board[i][j].get_piece()->get_symbol() != 'K')
                        {
                            if (board[i][j].get_piece()->cell_access(i, j, x_first, y_first+1 , board) == Chessman::Move_type::Attack)
                            {
                                return false;                               
                            }
                        }
                    }
                }
            }

            if (board[x_first][y_first + 3].get_piece()->get_symbol() == 'R' && !board[x_second][y_second + 3].get_piece()->is_moved())
            {
                return true;
            }
        }
        else if (y_first - y_second == 2 && board[x_first][y_first-1].get_piece() == nullptr && board[x_first][y_first-2].get_piece() == nullptr && board[x_first][y_first-3].get_piece() == nullptr)
        {
            for (size_t i = 0; i < 8; i++)
            {
                for (size_t j = 0; j < 8 ; j++)
                {
                    if (board[i][j].get_piece() != nullptr)
                    {
                        if (board[i][j].get_piece()->get_color() != get_color() && board[i][j].get_piece()->get_symbol() != 'K')
                        {
                            if (board[i][j].get_piece()->cell_access(i, j, x_first, y_first-1 , board) == Chessman::Move_type::Attack)
                            {
                                return false;                               
                            }
                        }
                    }                            
                }
            }
            if (board[x_first][y_first - 4].get_piece()->get_symbol() == 'R' && !board[x_second][y_second - 4].get_piece()->is_moved())
            {
                return true;
            }
        }
    }

    return false;
}

std::string King::random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    move_access.clear();
    
    if (x + 1 < 8 && y + 1 < 8)
    {
        move_access.insert(std::make_pair(x+1, y+1));
    }

    if (x+1 < 8)
    {
        move_access.insert(std::make_pair(x+1, y));
    }

    if (x+1 < 8 && y-1 >= 0)
    {
        move_access.insert(std::make_pair(x+1, y-1));
    }
    
    if (y-1 >= 0)
    {
        move_access.insert(std::make_pair(x, y-1));
    }
    if (x-1 >= 0 && y-1 >= 0)
    {
        move_access.insert(std::make_pair(x-1, y-1));
    }
    if (x-1 >= 0)
    {
        move_access.insert(std::make_pair(x-1, y));

    }
    if (x-1 >= 0 && y+1 < 8)
    {
        move_access.insert(std::make_pair(x-1, y+1));

    }
    if (y+1 < 8)
    {
        move_access.insert(std::make_pair(x, y+1));
    }

    std::default_random_engine Eng(static_cast<unsigned int>(time(NULL)));
    std::uniform_int_distribution<unsigned int> Rand(0 ,100);
    unsigned int number = Rand(Eng) % move_access.size();
    std::multimap<int, int>::iterator it = move_access.begin();
    
    for (size_t i = 0; i < number; i++)
    {
        it++;
    }
    return board[it->first][it->second].get_cell_id();
}