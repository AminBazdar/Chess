#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "chessman.hpp"
#include "cell.hpp"

using Positive_Score = int;

class Knight : public Chessman
{
public:
    Knight(Chessman::color_); //constructor
    bool cell_access(const std::string&, const std::string&, std::array<std::array<Cell, 8>, 8> &);
    //Positive_Score check_threats(std::string ,std::array<std::array<Cell, 8>, 8> &);
    //check threats after a move and returns score
    
};


#endif // KNIGHT_HPP
