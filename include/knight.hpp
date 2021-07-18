#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Knight : public Chessman
{
public:
    Knight(Chessman::color_); //constructor
    bool cell_access(const std::string&, const std::string&, std::array<std::array<Cell, 8>, 8> &);

};


#endif // KNIGHT_HPP
