#ifndef _CHESSMAN
#define _CHESSMAN

#include <iostream>
#include <array>
#include "cell.hpp"

using Position = std::string;

class Chessman
{
public:
    enum class color_ {Withe, Black};
    Chessman(Chessman::color_, std::string); //cosntructor
    virtual ~Chessman() {} // destructor

    void set_position(Position);
    Position get_position();
    
    void set_color(Chessman::color_);
    Chessman::color_ get_color();

    void set_symbol(std::string);
    std::string get_symbol();

    virtual bool cell_access(const std::string&, const std::string&, std::array<std::array<Cell, 8>, 8> &) = 0; //depend on piece type

private:
    Position position; //piece position
    Chessman::color_ color; //piece color
    std::string symbol;
};


#endif // _CHESSMAN
