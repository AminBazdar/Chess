#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
//#include "chessman.hpp"
class Chessman;

class Cell
{
public:
    Cell();
    std::string get_cell_id();
    void change_state(); //change is fill state
    bool is_fill();
    void set_piece(Chessman *&);
    Chessman*& get_piece();

private:
    void set_cell_id();
    std::string cell_id;
    bool cell_state = false; //is fill
    Chessman * piece = nullptr;
};

#endif // CELL_HPP
