#include "chessman.hpp"

Chessman::Chessman(Chessman::colorـ color, std::string symbol)
{
    set_color(color);
    set_symbol(symbol);
}

void Chessman::set_position(Cell *& position)
{
    this->position = position;
}

Cell*& Chessman::get_position()
{
    return position;
}

void Chessman::set_color(Chessman::colorـ color)
{
    this->color = color;
}

Chessman::colorـ Chessman::get_color()
{
    return color;
}

void Chessman::set_symbol(std::string symb)
{
    symbol = symb;
}

std::string Chessman::get_symbol()
{
    return symbol;
}