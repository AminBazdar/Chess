#include "cell.hpp"
#include <array>
#include <stdexcept>

const Cell& find_cell(const std::string& cell, std::array<std::array<Cell, 8>, 8>& board)
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (board[i][j].get_cell_id() == cell)
            {
                return board[i][j];
            }
        }
    }
    try
    {
        throw std::invalid_argument("Cell has not found !!!");
    }
    catch(const std::exception& e)
    {
        throw;
    }
}