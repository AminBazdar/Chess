#include "player.hpp"

Player::Player(Name name)
{
    set_name(name);
}

void Player::set_name(Name name)
{
    this->name = name;
}

Name Player::get_name()
{
    return name;
}

void Player::add_score(Score score)
{
    this->score += score;
}
Score Player::get_score()
{
    return score;
}
