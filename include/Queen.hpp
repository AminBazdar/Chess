#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "chessman.hpp"
#include "cell.hpp"

class Queen : public Chessman
{
public:
    Queen(Chessman::color_); //constructor
    bool cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &);
    
    Positive_Score check_threats(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &);
};

#endif // QUEEN_HPP
