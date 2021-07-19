#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

class ChessBoard
{
public:
    ChessBoard(const ChessBoard &) = delete;     // delete copy constructor (because of singleton)
    void operator=(const ChessBoard &) = delete; // delete operator= (because of singleton)

    static ChessBoard& make_chess_board(); // A fuction that can creat and return only one object of ChessBoard class (singleton method)
private:
    ChessBoard(); // private constructor
};

#endif // CHESSBOARD_HPP
