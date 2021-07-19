#include "chessman.hpp"

Chessman::Chessman(Chessman::color_ color, char symbol)
{
    set_color(color);
    set_symbol(symbol);
}

void Chessman::set_position(Position position)
{
    this->position = position;
}

Position Chessman::get_position()
{
    return position;
}

void Chessman::set_color(Chessman::color_ color)
{
    this->color = color;
}

Chessman::color_ Chessman::get_color()
{
    return color;
}

void Chessman::set_symbol(char symb)
{
    symbol = symb;
}

char Chessman::get_symbol()
{
    return symbol;
}