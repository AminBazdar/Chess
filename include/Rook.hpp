#ifndef ROOK_HPP
#define ROOK_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Rook : public Chessman
{
public:
    Rook(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
    Positive_Score move_score(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);

    std::string random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board);
};

#endif // ROOK_HPP
