#include "Pawn.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Pawn::Pawn(Chessman::color_ color) : Chessman(color, 'P') {}

Chessman::Move_type Pawn::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
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

Positive_Score Pawn::check_threats(const int &x, const int &y, std::array<std::array<Cell, 8>, 8> &board)
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

    return score;
}

Positive_Score Pawn::half_point(const int &x_first, const int &x_second)
{
    Positive_Score score = 0;

    if (get_color() == color_::White)
    {
        if (x_first == 4 && x_second == 3)
        {
            score += 3;
            return score;
        }
    }

    if (get_color() == color_::Black)
    {
        if (x_first == 3 && x_second == 4)
        {
            score += 3;
            return score;
        }
    }

    return score;
}
