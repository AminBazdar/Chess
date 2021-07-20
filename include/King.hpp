#ifndef KING_HPP
#define KING_HPP

#include "chessman.hpp"
#include "cell.hpp"

class King : public Chessman
{
public:
    King(Chessman::color_); //constructor
    bool cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
};

#endif // KING_HPP
