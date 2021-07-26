#include "Bishop.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>
#include  <map>
#include <random>
#include <iterator>

Bishop::Bishop(Chessman::color_ color) : Chessman(color, 'B') {}

Chessman::Move_type Bishop::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (abs(x_second - x_first) == abs(y_second - y_first))
    {
        int k = x_second > x_first ? 1 : -1;
        int z = y_second > y_first ? 1 : -1;

        for (int i = x_first + k, j = y_first + z; i != (x_second + k); i += k, j += z)
        {
            if (board[i][j].is_fill())
            {
                if (board[i][j].get_cell_id() == board[x_second][y_second].get_cell_id())
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

Positive_Score Bishop::move_score(const int &x, const int &y, std::array<std::array<Cell, 8>, 8> &board)
{
    Positive_Score score = 0;

    for (size_t i = 1, j = 1; x + i < 8 && y + j < 8; i++, j++)
    {
        if (board[x + i][y + j].is_fill() && board[x + i][y + j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if (board[x + i][y + j].is_fill())
        {
            switch (board[x + i][y + j].get_piece()->get_symbol())
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

    for (size_t i = 1, j = 1; x + i < 8 && y - j >= 0; i++, j++)
    {
        if (board[x + i][y - j].is_fill() && board[x + i][y - j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if (board[x + i][y - j].is_fill())
        {
            switch (board[x + i][y - j].get_piece()->get_symbol())
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

    for (size_t i = 1, j = 1; x - i >= 0 && y + j < 8; i++, j++)
    {
        if (board[x - i][y + j].is_fill() && board[x - i][y + j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if (board[x - i][y + j].is_fill())
        {
            switch (board[x - i][y + j].get_piece()->get_symbol())
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

    for (size_t i = 1, j = 1; x - i >= 0 && y - j >= 0; i++, j++)
    {
        if (board[x - i][y - j].is_fill() && board[x - i][y - j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if (board[x - i][y - j].is_fill())
        {
            switch (board[x - i][y - j].get_piece()->get_symbol())
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

std::string Bishop::random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    move_access.clear();

    for (size_t i = 1, j = 1; x + i < 8 && y + j < 8; i++, j++)
    {
        move_access.insert(std::make_pair(i, j));
    }

    for (size_t i = 1, j = 1; x + i < 8 && y - j >= 0; i++, j++)
    {
        move_access.insert(std::make_pair(i, j));
    }

    for (size_t i = 1, j = 1; x - i >= 0 && y + j < 8; i++, j++)
    {
        move_access.insert(std::make_pair(i, j));
    }

    for (size_t i = 1, j = 1; x - i >= 0 && y - j >= 0; i++, j++)
    {
        move_access.insert(std::make_pair(i, j));
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