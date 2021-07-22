#include "Queen.hpp"
#include "chessman.hpp"
#include "cell.hpp"
#include <cmath>
#include <array>

Queen::Queen(Chessman::color_ color) : Chessman(color, 'Q') {}

bool Queen::cell_access(const int& x_first, const int& y_first ,const int& x_second,const int& y_second, std::array<std::array<Cell, 8>, 8> &board)
{
    if (y_first == y_second)
    {
        int k = (x_second > x_first ? 1 : -1);
        for (int i = x_first + k; i != (x_second + k); i += k)
        {
            if (board[i][y_first].is_fill())
            {
                if (board[i][y_first].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (x_first == x_second)
    {
        int k = (y_second > y_first ? 1 : -1);
        for (int i = y_first + k; i != (y_second + k); i += k)
        {
            if (board[x_first][i].is_fill())
            {
                if (board[x_first][i].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (abs(x_second - x_first) == abs(y_second - y_first))
    {
        int k = x_second > x_first ? 1 : -1;
        int z = y_second > y_first ? 1 : -1;

        for (int i = x_first + k, j = y_first + z; i != (x_second + k); i += k, j += z)
        {
            if (board[i][j].is_fill())
            {
                if (board[i][j].get_cell_id() == board[x_second][y_second].get_cell_id() && board[x_second][y_second].get_piece()->get_color() != get_color())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

Positive_Score Queen::check_threats(const int& x, const int& y, std::array<std::array<Cell, 8>, 8> & board)
{
    Positive_Score score = 0;

    // threat move like a bishop 
    for (size_t i = 1, j = 1 ; x + i < 8 && y + j < 8 ; i++ , j++)
    {
        if (board[x+i][y+j].is_fill() && board[x+i][y+j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x+i][y+j].is_fill())
        {
            switch (board[x+i][y+j].get_piece()->get_symbol())
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
            break;
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
            switch (board[x+i][y-j].get_piece()->get_symbol())
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
            break;
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
            switch (board[x-i][y+j].get_piece()->get_symbol())
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
            break;
        }
    }

    for (size_t i = 1, j = 1 ; x - i <= 0 && y - j >= 0 ; i++ , j++)
    {
        if (board[x-i][y-j].is_fill() && board[x-i][y-j].get_piece()->get_color() == get_color())
        {
            break;
        }
        else if(board[x-i][y-j].is_fill())
        {
            switch (board[x-i][y-j].get_piece()->get_symbol())
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
            break;
        }
    }

    //threat move like a rook
    for (size_t i = 1; x + i < 8; i++)
    {
        if (board[x+i][y].is_fill() && board[x+i][y].get_piece()->get_color() == get_color())
        {
            break;
        }

        else if (board[x+i][y].is_fill())
        {
            switch (board[x+i][y].get_piece()->get_symbol())
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
            break;
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
            switch (board[x-i][y].get_piece()->get_symbol())
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
            break;
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
            switch (board[x][y+j].get_piece()->get_symbol())
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
            break;
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
            switch (board[x][y-j].get_piece()->get_symbol())
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
            break;
        }
    }

    return score;
}