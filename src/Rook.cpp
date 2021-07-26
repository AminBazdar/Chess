#include "Rook.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <array>
#include <map>
#include <random>
#include <iterator>

Rook::Rook(Chessman::color_ color) : Chessman(color, 'R') {}

Chessman::Move_type Rook::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (y_first == y_second)
    {
        int k = (x_second > x_first ? 1 : -1);
        for (int i = x_first + k; i != (x_second + k); i += k)
        {
            if (board[i][y_first].is_fill())
            {
                if (board[i][y_first].get_cell_id() == board[x_second][y_second].get_cell_id())
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
                else
                {
                    return Chessman::Move_type::Block;
                }
            }
        }
        return Chessman::Move_type::Empty;
    }
    if (x_first == x_second)
    {
        int k = (y_second > y_first ? 1 : -1);
        for (int i = y_first + k; i != (y_second + k); i += k)
        {
            if (board[x_first][i].is_fill())
            {
                if (board[x_first][i].get_cell_id() == board[x_second][y_second].get_cell_id())
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
                else
                {
                    return Chessman::Move_type::Block;
                }
            }
        }
        return Chessman::Move_type::Empty;
    }
    return Chessman::Move_type::Invalid;
}

Positive_Score Rook::move_score(const int &x, const int &y, std::array<std::array<Cell, 8>, 8> &board)
{
    Positive_Score score = 0;

    for (size_t i = 1; x + i < 8; i++)
    {
        if (board[x + i][y].is_fill() && board[x + i][y].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x + i][y].is_fill())
        {
            switch (board[x + i][y].get_piece()->get_symbol())
            {
            case 'P':
                score += 1;
                break;

            case 'Q':
                score += 5;
                break;

            case 'H':
            case 'B':
            case 'R':
                score += 2;
                break;

            case 'K':
                score += 10;
                break;
            }
            break;
        }
    }

    for (size_t i = 1; x - i >= 0; i++)
    {
        if (board[x - i][y].is_fill() && board[x - i][y].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x - i][y].is_fill())
        {
            switch (board[x - i][y].get_piece()->get_symbol())
            {
            case 'P':
                score += 1;
                break;

            case 'Q':
                score += 5;
                break;

            case 'H':
            case 'B':
            case 'R':
                score += 2;
                break;

            case 'K':
                score += 10;
                break;
            }
            break;
        }
    }

    for (size_t j = 1; y + j < 8; j++)
    {
        if (board[x][y + j].is_fill() && board[x][y + j].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x][y + j].is_fill())
        {
            switch (board[x][y + j].get_piece()->get_symbol())
            {
            case 'P':
                score += 1;
                break;

            case 'Q':
                score += 5;
                break;

            case 'H':
            case 'B':
            case 'R':
                score += 2;
                break;

            case 'K':
                score += 10;
                break;
            }
            break;
        }
    }

    for (size_t j = 1; y - j >= 0; j++)
    {
        if (board[x][y - j].is_fill() && board[x][y - j].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x][y - j].is_fill())
        {
            switch (board[x][y - j].get_piece()->get_symbol())
            {
            case 'P':
                score += 1;
                break;

            case 'Q':
                score += 5;
                break;

            case 'H':
            case 'B':
            case 'R':
                score += 2;
                break;

            case 'K':
                score += 10;
                break;
            }
            break;
        }
    }

    return score;
}

std::string Rook::random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    move_access.clear();
    for (size_t i = 1; x + i < 8; i++)
    {
        move_access.insert(std::make_pair(i, y));
    }

    for (size_t i = 1; x - i >= 0; i++)
    {
        move_access.insert(std::make_pair(i, y));
    }

    for (size_t j = 1; y + j < 8; j++)
    {
        move_access.insert(std::make_pair(x, j));
    }

    for (size_t j = 1; y - j >= 0; j++)
    {
        move_access.insert(std::make_pair(x, j));
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