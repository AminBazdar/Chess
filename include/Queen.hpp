#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Queen : public Chessman
{
public:
    Queen(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
    Positive_Score move_score(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);
    
    std::string random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board);

};

#endif // QUEEN_HPP
