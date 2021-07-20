#include "Bishop.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Bishop::Bishop(Chessman::color_ color) : Chessman(color, 'B') {}

bool Bishop::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (abs(x_second - x_first) == abs(y_second - y_first))
    {
        int k = x_second > x_first ? 1 : -1;
        int z = y_second > y_first ? 1 : -1;

        for (int i = x_first + k, j = y_first + z; i != (x_second + k); i += k, j += z)
        {
            if (board[i][j].is_fill())
            {
                if (board[i][j].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
