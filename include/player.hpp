#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using Name = std::string;
using Score = int;

class Player
{
public:
    Player(Name);

    void set_name(Name);
    Name get_name();

    void add_score(Score);
    Score get_score();

private:
    Name name;
    Score score = 0;
};



#endif // PLAYER_HPP
