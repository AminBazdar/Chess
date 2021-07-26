#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Bishop : public Chessman
{
public:
    Bishop(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);

    Positive_Score move_score(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);

    std::string random_cell(const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
};

#endif // BISHOP_HPP
