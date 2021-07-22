#include "Knight.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Knight::Knight(Chessman::color_ color) : Chessman(color, 'H') {}

bool Knight::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{

    if ((abs(x_first - x_second) == 2 && abs(y_first - y_second) == 1) ||
        (abs(x_first - x_second) == 1 && abs(y_first - y_second) == 2))
    {
        if (!board[x_second][y_second].is_fill())
        {
            return true;
        }
        else if (board[x_second][y_second].get_piece()->get_color() != get_color())
        {
            return true;
        }
    }

    return false;
}

Positive_Score Knight::check_threats(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
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