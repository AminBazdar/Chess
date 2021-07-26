#include "Knight.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>
#include <map>
#include <random>
#include <iterator>

Knight::Knight(Chessman::color_ color) : Chessman(color, 'H') {}

Chessman::Move_type Knight::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{

    if ((abs(x_first - x_second) == 2 && abs(y_first - y_second) == 1) ||
        (abs(x_first - x_second) == 1 && abs(y_first - y_second) == 2))
    {
        if (!board[x_second][y_second].is_fill())
        {
            return Chessman::Move_type::Empty;
        }
        else if (board[x_second][y_second].get_piece()->get_color() != get_color())
        {
            return Chessman::Move_type::Attack;
        }
        else
        {
            return Chessman::Move_type::SameColor;
        }
    }

    return Chessman::Move_type::Invalid;
}

Positive_Score Knight::move_score(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    Positive_Score score = 0;
    
    if (x + 2 < 8 && y + 1 < 8)
    {       
        if (board[x+2][y+1].is_fill() && board[x+2][y+1].get_piece()->get_color() != get_color())
        {        
            switch (board[x+2][y+1].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }        
    }
    
    if (x + 2 < 8 && y - 1 >= 0)
    {
        if (board[x+2][y-1].is_fill() && board[x+2][y-1].get_piece()->get_color() != get_color())
        {
            switch (board[x+2][y-1].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }        
    }

    if (x - 2 >= 0 && y + 1 < 8)
    {
        if (board[x-2][y+1].is_fill() && board[x-2][y+1].get_piece()->get_color() != get_color())
        {
            switch (board[x-2][y+1].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }
    }

    if (x - 2 >= 0 && y - 1 >= 0)
    {            
        if (board[x-2][y-1].is_fill() && board[x-2][y-1].get_piece()->get_color() != get_color())
        {
            switch (board[x-2][y-1].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }
    }

    if (x + 1 < 8 && y + 2 < 8)
    {            
        if (board[x+1][y+2].is_fill() && board[x+1][y+2].get_piece()->get_color() != get_color())
        {
            switch (board[x+1][y+2].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }   
    }

    if (x - 1 >= 0 && y + 2 < 8)
    {            
        if (board[x-1][y+2].is_fill() && board[x-1][y+2].get_piece()->get_color() != get_color())
        {
            switch (board[x-1][y+2].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }   
    }

    if (x + 1 < 8 && y - 2 >= 0)
    {            
        if (board[x+1][y-2].is_fill() && board[x+1][y-2].get_piece()->get_color() != get_color())
        {
            switch (board[x+1][y-2].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }   
    }

    if (x - 1 >= 0 && y - 2 >= 0)
    {
        if (board[x-1][y-2].is_fill() && board[x-1][y-2].get_piece()->get_color() != get_color())
        {
            switch (board[x-1][y-2].get_piece()->get_symbol())
            {
                case 'P':
                    score += 1;
                    break;

                case 'Q':
                    score += 5;
                    break;

                case 'H':
                case 'B':
                case 'R':
                    score += 2;
                    break;
                
                case 'K':
                    score += 10;
                    break;
            }
        }    
    }

    return score;
}

std::string Knight::random_cell(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    move_access.clear();

    if (x + 2 < 8 && y + 1 < 8)
    {       
        move_access.insert(std::make_pair(x+2, y+1));
    }
    
    if (x + 2 < 8 && y - 1 >= 0)
    {
        move_access.insert(std::make_pair(x+2, y-1));
    }

    if (x - 2 >= 0 && y + 1 < 8)
    {
        move_access.insert(std::make_pair(x-2, y+1));
    }

    if (x - 2 >= 0 && y - 1 >= 0)
    {            
        move_access.insert(std::make_pair(x-2, y-1));
    }

    if (x + 1 < 8 && y + 2 < 8)
    {            
        move_access.insert(std::make_pair(x+1, y+2));
    }

    if (x - 1 >= 0 && y + 2 < 8)
    {            
        move_access.insert(std::make_pair(x-1, y+2));
    }

    if (x + 1 < 8 && y - 2 >= 0)
    {            
        move_access.insert(std::make_pair(x+1, y-2));
    }

    if (x - 1 >= 0 && y - 2 >= 0)
    {
        move_access.insert(std::make_pair(x-1, y-2));
    }

    std::default_random_engine Eng(static_cast<unsigned int>(time(NULL)));
    std::uniform_int_distribution<unsigned int> Rand(0 ,100);
    unsigned int number = Rand(Eng) % move_access.size();
    std::multimap<int, int>::iterator it = move_access.begin();
    
    for (size_t i = 0; i < number; i++)
    {
        it++;
    }
    return board[it->first][it->second].get_cell_id();
}
