#include "King.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

King::King(Chessman::color_ color) : Chessman(color, 'K') {}

Chessman::Move_type King::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if ((abs(x_second - x_first) == 1 && (abs(y_second - y_first) == 1 || abs(y_second - y_first) == 0)) || (abs(x_second - x_first) == 0 && abs(y_second - y_first) == 1))
    {
        if (board[x_second][y_second].is_fill())
        {
            if (board[x_second][y_second].get_piece()->get_color() != get_color())
            {
                return Chessman::Move_type::Attack;
            }
            else
            {
                return Chessman::Move_type::SameColor;
            }
        }
        return Chessman::Move_type::Empty;
    }
    return Chessman::Move_type::Invalid;
}

bool King::is_safe(std::array<std::array<Cell, 8>, 8>& board)
{
    std::string origin = get_position();
    int x = 8 - (origin[1] - 48); 
    int y = origin[0] - 65;

    for (size_t i = 1; x + i < 8; i++)
    {
        if (board[x+i][y].is_fill() && board[x+i][y].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x+i][y].is_fill())
        {
            return false;
        }
    }

    for (size_t i = 1; x - i >= 0 ; i++)
    {
        if (board[x-i][y].is_fill() && board[x-i][y].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x-i][y].is_fill())
        {
            return false;
        }
    }
    
    for (size_t j = 1 ; y + j < 8 ; j++)
    {
        if (board[x][y+j].is_fill() && board[x][y+j].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x][y+j].is_fill())
        {
            return false;
        }
    }
    
    for (size_t j = 1 ; y - j >= 0 ; j++)
    {
        if (board[x][y-j].is_fill() && board[x][y-j].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x][y-j].is_fill())
        {
            return false;
        }
    }

    for (size_t i = 1, j = 1 ; x + i < 8 && y + j < 8 ; i++ , j++)
    {
        if (board[x+i][y+j].is_fill() && board[x+i][y+j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x+i][y+j].is_fill())
        {
            return false;
        }
    }

    for (size_t i = 1, j = 1 ; x + i < 8 && y - j >= 0 ; i++ , j++)
    {
        if (board[x+i][y-j].is_fill() && board[x+i][y-j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x+i][y-j].is_fill())
        {
            return false;
        }
    }

    for (size_t i = 1, j = 1 ; x - i >= 0 && y + j < 8 ; i++ , j++)
    {
        if (board[x-i][y+j].is_fill() && board[x-i][y+j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x-i][y+j].is_fill())
        {
            return false;
        }
    }

    for (size_t i = 1, j = 1 ; x - i >= 0 && y - j >= 0 ; i++ , j++)
    {
        if (board[x-i][y-j].is_fill() && board[x-i][y-j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x-i][y-j].is_fill())
        {
            return false;
        }
    }

    if (x + 2 < 8 && y + 1 < 8)
    {       
        if (board[x+2][y+1].is_fill() && board[x+2][y+1].get_piece()->get_color() != get_color())
        {        
            return false;
        }        
    }
    
    if (x + 2 < 8 && y - 1 >= 0)
    {
        if (board[x+2][y-1].is_fill() && board[x+2][y-1].get_piece()->get_color() != get_color())
        {
            return false;
        }        
    }

    if (x - 2 >= 0 && y + 1 < 8)
    {
        if (board[x-2][y+1].is_fill() && board[x-2][y+1].get_piece()->get_color() != get_color())
        {
            return false;
        }
    }

    if (x - 2 >= 0 && y - 1 >= 0)
    {            
        if (board[x-2][y-1].is_fill() && board[x-2][y-1].get_piece()->get_color() != get_color())
        {
            return false;
        }
    }

    if (x + 1 < 8 && y + 2 < 8)
    {            
        if (board[x+1][y+2].is_fill() && board[x+1][y+2].get_piece()->get_color() != get_color())
        {
            return false;
        }   
    }

    if (x - 1 >= 0 && y + 2 < 8)
    {            
        if (board[x-1][y+2].is_fill() && board[x-1][y+2].get_piece()->get_color() != get_color())
        {
            return false;
        }   
    }

    if (x + 1 < 8 && y - 2 >= 0)
    {            
        if (board[x+1][y-2].is_fill() && board[x+1][y-2].get_piece()->get_color() != get_color())
        {
            return false;
        }   
    }

    if (x - 1 >= 0 && y - 2 >= 0)
    {
        if (board[x-1][y-2].is_fill() && board[x-1][y-2].get_piece()->get_color() != get_color())
        {
            return false;
        }    
    }
    
    return true;
}