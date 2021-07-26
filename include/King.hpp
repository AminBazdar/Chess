#ifndef KING_HPP
#define KING_HPP

#include "chessman.hpp"
#include "cell.hpp"

class King : public Chessman
{
public:
    King(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);

    Positive_Score move_score(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board) {return 0;}
    // king connot threat pieces

    bool is_castling(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    // check for doing castling move 

    std::string random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board);
};

#endif // KING_HPP
