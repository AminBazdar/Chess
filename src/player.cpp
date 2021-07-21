#include "player.hpp"

Player::Player()
{ }

void Player::set_name(Name name)
{
    this->name = name;
}

Name Player::get_name()
{
    return name;
}

void Player::add_positive_score(Score score)
{
    this->positive_score += score;
}

Score Player::get_positive_score()
{
    return positive_score;
}

// void Player::set_king(King& king)
// {
//     this->king = &king;
// }

// King* Player::get_king()
// {
//     return king;
// }