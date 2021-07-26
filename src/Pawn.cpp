#include "Pawn.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>
#include <map>
#include <random>
#include <iterator>

Pawn::Pawn(Chessman::color_ color) : Chessman(color, 'P') {}

Chessman::Move_type Pawn::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    // if (abs(x_first - x_second) == 2 && y_first - y_second == 0 && check_give_enpassant(x_first, y_first, x_second, y_second, board))
    // {
    //     return Move_type::Give_Enpassant;
    // }

    // if (can_enpassant && check_do_enpassant(x_first, y_first, x_second, y_second, board))
    // {
        
    // }
    
    
    if (get_color() == color_::White)
    {
        if (x_first == 6)
        {
            if (x_second - x_first == -1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    return Chessman::Move_type::Empty;
                }
                if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true)
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
                return Chessman::Move_type::Invalid;
            }
            if (x_second - x_first == -2)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    if (board[x_second + 1][y_second].is_fill() == false)
                    {
                        return Chessman::Move_type::Empty;
                    }
                    else
                    {
                        return Chessman::Move_type::Block;
                    }
                }
                return Chessman::Move_type::Invalid;
            }
        }
        else
        {
            if (x_second - x_first == -1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    return Chessman::Move_type::Empty;
                }
                else if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true)
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
                return Chessman::Move_type::Invalid;
            }
        }
    }
    if (get_color() == color_::Black)
    {
        if (x_first == 1)
        {
            if (x_second - x_first == 1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    return Chessman::Move_type::Empty;
                }
                if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true)
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
                return Chessman::Move_type::Invalid;
            }
            if (x_second - x_first == 2)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    if (board[x_second - 1][y_second].is_fill() == false)
                    {
                        return Chessman::Move_type::Empty;
                    }
                    else
                    {
                        return Chessman::Move_type::Block;
                    }
                }
                return Chessman::Move_type::Invalid;
            }
        }
        else
        {
            if (x_second - x_first == 1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    return Chessman::Move_type::Empty;
                }
                else if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true)
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
                return Chessman::Move_type::Invalid;
            }
        }
    }
    return Chessman::Move_type::Invalid;
};

Positive_Score Pawn::move_score(const int &x, const int &y, std::array<std::array<Cell, 8>, 8> &board)
{
    Positive_Score score = 0;

    if (get_color() == color_::White)
    {
        if ((x - 1 >= 0 && y + 1 < 8) && board[x - 1][y + 1].is_fill() && board[x - 1][y + 1].get_piece()->get_color() != get_color())
        {
            switch (board[x - 1][y + 1].get_piece()->get_symbol())
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
        }

        if ((x - 1 >= 0 && y - 1 >= 0) && board[x - 1][y - 1].is_fill() && board[x - 1][y - 1].get_piece()->get_color() != get_color())
        {
            switch (board[x - 1][y - 1].get_piece()->get_symbol())
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
        }
    }

    if (get_color() == color_::Black)
    {
        if ((x + 1 < 8 && y + 1 < 8) && board[x + 1][y + 1].is_fill() && board[x + 1][y + 1].get_piece()->get_color() != get_color())
        {
            switch (board[x + 1][y + 1].get_piece()->get_symbol())
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
        }

        if ((x + 1 < 8 && y - 1 >= 0) && board[x + 1][y - 1].is_fill() && board[x + 1][y - 1].get_piece()->get_color() != get_color())
        {
            switch (board[x + 1][y - 1].get_piece()->get_symbol())
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
        }
    }
    score += half_point(x);

    return score;
}

Positive_Score Pawn::half_point(const int &x_second)
{
    Positive_Score score = 0;

    if (get_color() == color_::White)
    {
        if (x_second == 3)
        {
            score += 3;
            return score;
        }
    }

    if (get_color() == color_::Black)
    {
        if (x_second == 4)
        {
            score += 3;
            return score;
        }
    }

    return score;
}

std::string Pawn::random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    move_access.clear();
    if (get_color() == color_::White)
    {
        if (x == 6)
        {
            move_access.insert(std::make_pair(x-1, y));
            move_access.insert(std::make_pair(x-2, y));
        }
        else
        {
            move_access.insert(std::make_pair(x-1, y));
        }

        if(x - 1 >= 0 && y + 1 < 8 )
        {
            move_access.insert(std::make_pair(x-1, y+1));
        }

        if (x - 1 >= 0 && y - 1 >= 0)
        {
            move_access.insert(std::make_pair(x-1, y-1));
        }
    }

    if (get_color() == color_::Black)
    {
        if (x == 1)
        {
            move_access.insert(std::make_pair(x+1, y));
            move_access.insert(std::make_pair(x+2, y));
        }
        else
        {
            move_access.insert(std::make_pair(x+1, y));
        }

        if(x + 1 < 8 && y - 1 >= 0 )
        {
            move_access.insert(std::make_pair(x+1, y-1));
        }

        if (x + 1 < 8 && y + 1 < 8)
        {
            move_access.insert(std::make_pair(x+1, y+1));
        }
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
