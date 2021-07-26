#include "player.hpp"

Player::Player()
{}

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

void Player::add_negative_score(Score score)
{
    negative_score += score;
}

Score Player::get_negative_score()
{
    return negative_score;
}

void Player::add_attacked_piece(Chessman *piece)
{
    attacked_pieces.push_back(piece);
}

void Player::operator=(Player& player)
{
    name = player.name;
    positive_score = player.positive_score;
    negative_score = player.negative_score;
    attacked_pieces = player.attacked_pieces;
}