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

    void set_king(Chessman *);
    Chessman* get_king();

    void add_attacked_piece(Chessman *);

private:
    Name name;
    Score positive_score = 0;
    Chessman * king = nullptr; 
    std::vector<Chessman*> attacked_pieces;
};

#endif // PLAYER_HPP
