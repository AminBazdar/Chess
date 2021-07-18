#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Knight : public Chessman
{
public:
    Knight(Cell *&, Chessman::colorـ);
    bool cell_access(Cell *);

};


#endif // KNIGHT_HPP
