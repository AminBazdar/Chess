#ifndef _CHESSMAN
#define _CHESSMAN

#include <iostream>

using Position = std::string;

//hi masoud: this class code is just a first idea,,, you can add change it if you want to 
class Chessman
{
public:
    enum class colorـ {Withe, Black};
    Chessman(Chessman::colorـ); //cosntructor

    void set_position(Position);
    Position get_position();
    
    void set_color(Chessman::colorـ);
    Chessman::colorـ get_color();

    virtual void move() = 0; //depend on piece type

private:
    Position position; //piece position
    Chessman::colorـ color; //piece color

};


#endif // _CHESSMAN
