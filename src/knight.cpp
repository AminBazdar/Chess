#include "knight.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>

Knight::Knight(Cell *& cell, Chessman::colorـ color) : Chessman(color, "H")
{
    set_position(cell);
}

bool Knight::cell_access(Cell * destination)
{
    int x = get_position()->get_cell_id()[0] - 64; //converting origin position id to integer
    int y = ((int)get_position()->get_cell_id()[1] - 48);
    int xd = destination->get_cell_id()[0] - 64; //converting destination position id to integer
    int yd = ((int)destination->get_cell_id()[1]) - 48;

    if (abs(x - xd ) == 2 && abs(y - yd) == 1 || 
        abs(x - xd ) == 1 && abs(y - yd) == 2 )  
    {
        if (!destination->is_fill())
        {
            return true;
        }
        if (destination->is_fill())
        {
            if (destination->get_piece()->get_color() == get_color())
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