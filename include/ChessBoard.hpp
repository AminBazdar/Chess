#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include "cell.hpp"
#include "player.hpp"
#include "chessman.hpp"
#include <array>
#include <vector>

using Score = int;

class ChessBoard
{
public:
    ChessBoard();                                 //constructor
    ~ChessBoard();                               // destructor

    void movePiece(std::string);                 // a function that enter a move after validation it

    Score attack_score(char);                   //attacks and returns the score of attack
    Chessman* game_check(Chessman::color_);
    bool checkmate(Chessman::color_);

    Chessman::color_ turn = Chessman::color_::White;               //show which player turn is

    std::array<Player , 2> player;              //index 0 for player with white pieces and 1 for black
    
    void Check_last_move(std::string);

    void operator=(ChessBoard &);
    
    std::string random_move();
    
private:                                
    std::array<std::array<Cell, 8>, 8> cells;   //a 2D array of Cell for 64 cells of chess board
};

#endif // CHESSBOARD_HPP
