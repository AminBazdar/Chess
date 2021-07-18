#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

class Cell
{
public:
    Cell();
    std::string get_cell_id();
    void change_state(); //change is fill state
    bool is_fill(); 

private:
    void set_cell_id();
    std::string cell_id;
    bool cell_state = false; //is fill
};

#endif // CELL_HPP
