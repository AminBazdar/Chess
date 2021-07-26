#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "chessman.hpp"
#include "cell.hpp"

using Positive_Score = int;

class Knight : public Chessman
{
public:
    Knight(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
    
    Positive_Score move_score(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);
    //check threats after a move and returns score

    std::string random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board);
};


#endif // KNIGHT_HPP
