#ifndef PAWN_HPP
#define PAWN_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Pawn : public Chessman
{
public:
    Pawn(Chessman::color_); //constructor
    bool cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
};

#endif // PAWN_HPP
