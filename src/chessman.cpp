#include "chessman.hpp"

Chessman::Chessman(Chessman::colorـ color)
{
    set_color(color);
}

void Chessman::set_position(Position position)
{
    this->position = position;
}

Position Chessman::get_position()
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

