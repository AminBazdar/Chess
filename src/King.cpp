#include "King.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

King::King(Chessman::color_ color) : Chessman(color, 'K') {}

bool King::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if ((abs(x_second - x_first) == 1 && (abs(y_second - y_first) == 1 || abs(y_second - y_first) == 0)) || (abs(x_second - x_first) == 0 && abs(y_second - y_first) == 1))
    {
        if (board[x_second][y_second].is_fill())
        {
            if (board[x_second][y_second].get_piece()->get_color() != get_color())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
