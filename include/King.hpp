#ifndef KING_HPP
#define KING_HPP

#include "chessman.hpp"
#include "cell.hpp"

class King : public Chessman
{
public:
    King(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);

    Positive_Score check_threats(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board) {return 0;}
    // king connot threat pieces

    bool is_safe(std::array<std::array<Cell, 8>, 8>&);
    
};

#endif // KING_HPP
