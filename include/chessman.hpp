#ifndef _CHESSMAN
#define _CHESSMAN

#include <iostream>
#include "cell.hpp"

//hi masoud: this class code is just a first idea,,, you can add change it if you want to 

// struct Position
// {
//     int x; // piece x
//     int y; // piece y
// };

class Chessman
{
public:
    enum class colorـ {Withe, Black};
    Chessman(Chessman::colorـ, std::string); //cosntructor
    virtual ~Chessman() {} // destructor

    void set_position(Cell *&);
    Cell*& get_position();
    
    void set_color(Chessman::colorـ);
    Chessman::colorـ get_color();

    void set_symbol(std::string);
    std::string get_symbol();

    virtual bool cell_access(Cell*&) = 0; //depend on piece type

private:
    Cell* position; //piece position
    Chessman::colorـ color; //piece color
    std::string symbol;
};


#endif // _CHESSMAN
