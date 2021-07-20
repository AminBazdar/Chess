#include "Knight.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Knight::Knight(Chessman::color_ color) : Chessman(color, 'H') {}

bool Knight::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{

    

    if (abs(x_first - x_second) == 2 && abs(y_first - y_second) == 1 ||
        abs(x_first - x_second) == 1 && abs(y_first - y_second) == 2)
    {
        if (!board[x_second][y_second].is_fill())
        {
            return true;
        }
        else if (board[x_second][y_second].get_piece()->get_color() != get_color())
        {
            return true;
        }
    }

    return false;
}

// Positive_Score Knight::check_threats(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
// {
// }