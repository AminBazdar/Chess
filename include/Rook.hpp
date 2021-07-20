#ifndef ROOK_HPP
#define ROOK_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Rook : public Chessman
{
public:
    Rook(Chessman::color_); //constructor
    bool cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
};

#endif // ROOK_HPP
