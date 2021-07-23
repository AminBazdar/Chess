#include <iostream>
#include <array>
#include <string>
#include "chessman.hpp"
#include "cell.hpp"
#include "Knight.hpp"
#include "ChessBoard.hpp"

using namespace std;

void print(ChessBoard & board)
{
for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ((board.cells[i][j].get_piece() == nullptr) ? ' ' : board.cells[i][j].get_piece()->get_symbol()) << board.cells[i][j].get_cell_id() << '\t';
        }
        cout << endl;
    }
}

int main()
{
    ChessBoard &board = ChessBoard::make_chess_board();
    string order = "\n";
    while (1)
    {
        
        cout << order << endl;
        print(board);
        cin >> order;
        system("clear");
        board.movePiece(order);
        
    }
    
   

    return 0;
}