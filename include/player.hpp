#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "King.hpp"
#include "chessman.hpp"

using Name = std::string;
using Score = int;

class Player
{
public:
    Player();

    void set_name(Name);
    Name get_name();

    void add_positive_score(Score);
    Score get_positive_score();
    void add_negative_score(Score);
    Score get_negative_score();

    void add_attacked_piece(Chessman *);
    //bool can_enpassant = false;
    
    std::string last_move;
    void operator=(Player&);
    
private:
    Name name;
    Score positive_score = 0;
    Score negative_score = 0;
    std::vector<Chessman*> attacked_pieces;
};

#endif // PLAYER_HPP
