#include "knight.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include "util.hpp"
#include <cmath>
#include <array>

Knight::Knight(Chessman::colorـ color) : Chessman(color, "H") {}

bool Knight::cell_access(const std::string& origin, const std::string& destination, std::array<std::array<Cell, 8>, 8>& board)
{
    int x = origin[0] - 64; //converting origin position id to integer
    int y = origin[1] - 48;
    int xd = destination[0] - 64; //converting destination position id to integer
    int yd = destination[1] - 48;

    Cell temp_origin = find_cell(origin, board);
    Cell temp_destination = find_cell(destination, board);

    if (abs(x - xd ) == 2 && abs(y - yd) == 1 || 
        abs(x - xd ) == 1 && abs(y - yd) == 2 )  
    {
        if (!temp_destination.is_fill())
        {
            return true;
        }
        if (temp_destination.is_fill())
        {
            if (temp_destination.get_piece()->get_color() == get_color())
            {
                return false;
            }
            else 
            {
                return true;
            }
        }
    }
    
    return false;
}