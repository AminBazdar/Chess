#ifndef _GAME
#define _GAME

#include "ChessBoard.hpp"
#include "chessman.hpp"

class Game
{
public:
    void get_command();

    void undo();
    bool is_undo = false;

    void extra_move();
    bool is_extra_move = false;

    void set_name(std::string);
    std::string get_name();
    
private:
    ChessBoard main_board;    //main board
    ChessBoard last_board;    //last board used for undo key
    std::string game_name;
};

#endif // _GAME
