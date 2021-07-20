#include "Pawn.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Pawn::Pawn(Chessman::color_ color) : Chessman(color, 'P') {}

bool Pawn::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (get_color() == color_::White)
    {
        if (x_first == 6)
        {
            if (x_second - x_first == -1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    return true;
                }
                if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                return false;
            }
            if (x_second - x_first == -2)
            {
                if (y_first == y_second && board[x_second + 1][y_second].is_fill() == false && board[x_second][y_second].is_fill() == false)
                {
                    return true;
                }
                return false;
            }
        }
        else
        {
            bool access = false;
            if (x_second - x_first == -1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    access = true;
                }
                else if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    access = true;
                }
                if (access == true && x_second == 0)
                {
                    // residan sarbaz be akharin khane !!!!!!!!!
                    // neveshtan function marboote !!!!!!!!!!
                    return true;
                }
                return access;
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
                    return true;
                }
                if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                return false;
            }
            if (x_second - x_first == 2)
            {
                if (y_first == y_second && board[x_second - 1][y_second].is_fill() == false && board[x_second][y_second].is_fill() == false)
                {
                    return true;
                }
                return false;
            }
        }
        else
        {
            bool access = false;
            if (x_second - x_first == 1)
            {
                if (y_first == y_second && board[x_second][y_second].is_fill() == false)
                {
                    access = true;
                }
                else if (abs(y_second - y_first) == 1 && board[x_second][y_second].is_fill() == true && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    access = true;
                }
                if (access == true && x_second == 7)
                {
                    // residan sarbaz be akharin khane !!!!!!!!!
                    // neveshtan function marboote !!!!!!!!!!
                    return true;
                }
                return access;
            }
        }
    }
    return false;
}