#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "King.hpp"

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

    void set_king(King &);
    King* get_king();

private:
    Name name;
    Score positive_score = 0;
    King * king = nullptr; 
};

#endif // PLAYER_HPP
