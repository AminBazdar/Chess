#include "chessman.hpp"

Chessman::Chessman(Chessman::color_ color, std::string symbol)
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

void Chessman::set_symbol(std::string symb)
{
    symbol = symb;
}

std::string Chessman::get_symbol()
{
    return symbol;
}