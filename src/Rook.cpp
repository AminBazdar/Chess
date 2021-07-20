#include "Rook.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <array>

Rook::Rook(Chessman::color_ color) : Chessman(color, 'R') {}

bool Rook::cell_access(const int &x_first, const int &y_first, const int &x_second, const int &y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (y_first == y_second)
    {
        int k = (x_second > x_first ? 1 : -1);
        for (int i = x_first + k; i != (x_second + k); i += k)
        {
            if (board[i][y_first].is_fill())
            {
                if (board[i][y_first].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
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
    if (x_first == x_second)
    {
        int k = (y_second > y_first ? 1 : -1);
        for (int i = y_first + k; i != (y_second + k); i += k)
        {
            if (board[x_first][i].is_fill())
            {
                if (board[x_first][i].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
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
