#ifndef _CHESSMAN
#define _CHESSMAN

#include <iostream>
#include <array>
#include "cell.hpp"

using Position = std::string;
using Positive_Score = int;

class Chessman
{
public:
    enum class Move_type {Attack, Block, Empty, SameColor, Invalid};
    enum class color_ {White, Black};
    Chessman(Chessman::color_, char); //cosntructor
    virtual ~Chessman() {} // destructor

    void set_position(Position);
    Position get_position();
    
    void set_color(Chessman::color_);
    Chessman::color_ get_color();

    void set_symbol(char);
    char get_symbol();

    virtual Chessman::Move_type cell_access(const int&, const int&, const int&, const int&, std::array<std::array<Cell, 8>, 8> &) = 0; //depend on piece type
    
    virtual Positive_Score check_threats(const int&, const int& ,std::array<std::array<Cell, 8>, 8> &) = 0;
    //checking threats after move and returns score
    
private:
    Position position; //piece position
    Chessman::color_ color; //piece color
    char symbol;
};


#endif // _CHESSMAN
