#include "cell.hpp"
#include "chessman.hpp"
#include <string>
#include <array>

Cell::Cell()
{
    set_cell_id();
}

void Cell::set_cell_id()
{
    std::array <std::string, 8> col = {"A", "B", "C", "D", "E", "F", "G", "H"};
    static int row = 8;
    static int ptr = 0;
    static int counter = 1;
    if (counter > 64)
    {
        return;
    }

    if (ptr > 7)
    {
        ptr = 0;
        --row;
    }
    cell_id = col[ptr] + std::to_string(row);
    ++ptr;
    ++counter; 
}

std::string Cell::get_cell_id()
{
    return cell_id;
}

void Cell::change_state(bool fill)
{
    cell_state = fill;
}

bool Cell::is_fill()
{
    return cell_state;
}

void Cell::set_piece(Chessman* piece)
{
    this->piece = piece;
    if (piece != nullptr)
    {
        piece->set_position(get_cell_id());
        cell_state = true;
    }
    else
    {
        cell_state = false;
    }
}

Chessman*& Cell::get_piece()
{
    return piece;
}

void Cell::operator=(Cell cell)
{
    cell_id = cell.cell_id;
    cell_state = cell.cell_state;
    piece = cell.piece;
}