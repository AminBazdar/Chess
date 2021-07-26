#ifndef PAWN_HPP
#define PAWN_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Pawn : public Chessman
{
public:
    Pawn(Chessman::color_); //constructor
    Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
    Positive_Score move_score(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);
    Positive_Score half_point(const int&);
    //bool check_give_enpassant(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    //bool check_do_enpassant(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    //bool can_be_enpassant = false;
    //bool can_do_enpassant = false;

    std::string random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board);
};

#endif // PAWN_HPP
