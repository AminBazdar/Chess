#include "game.hpp"
#include "chessman.hpp"

void Game::get_command()
{
    //call move method and all of commands 
    //this method codes are depend on ui
    std::string move;

    if (main_board.game_check(main_board.turn) != nullptr && main_board.checkmate(main_board.turn))
    {
        if (main_board.turn == Chessman::color_::White)
        {
            main_board.player[1].add_positive_score(40);
            return; //end of the game
        }
        if (main_board.turn == Chessman::color_::Black)
        {
            main_board.player[0].add_positive_score(40);
            return; //end of the game
        }
    }

    if (main_board.turn == Chessman::color_::White && main_board.player[0].get_negative_score() >= 15)
    {
        move = main_board.random_move();
        last_board = main_board; 
        main_board.movePiece(move);
        main_board.turn = Chessman::color_::Black;
        main_board.player[0].add_positive_score(-15);
    }

    else if (main_board.turn == Chessman::color_::Black && main_board.player[1].get_negative_score() >= 15)
    {
        move = main_board.random_move();
        last_board = main_board; 
        main_board.movePiece(move);
        main_board.turn = Chessman::color_::White;
        main_board.player[1].add_positive_score(-15);
    }

    if (is_undo)
    {
        undo();
        return;
    }

    if (is_extra_move)
    {
        extra_move();
        return;
    }

    //get the move command in ui and pass it to movepiece
    last_board = main_board; 
    main_board.movePiece(move);
    
}

void Game::undo()
{
    if (main_board.turn == Chessman::color_::Black && main_board.turn != last_board.turn)
    {
        main_board.player[0].add_negative_score(5);
        main_board = last_board;
    }

    else if(main_board.turn == Chessman::color_::White && main_board.turn != last_board.turn)
    {
        main_board.player[1].add_negative_score(5);
        main_board = last_board;

    }

    is_undo = false;
}

void Game::extra_move()
{
    std::string move;
    int dif;
    if (main_board.turn == Chessman::color_::White)
    {
        main_board.player[0].add_positive_score(-30);

        for (size_t i = 0; i < 2;)
        {
            //getting move command in ui and pass it to movepiece 
            if (main_board.turn == Chessman::color_::White && main_board.player[0].get_negative_score() >= 15)
            {
                move = main_board.random_move();
                last_board = main_board; 
                main_board.movePiece(move);
                main_board.turn = Chessman::color_::Black;
                main_board.player[0].add_positive_score(-15);
                i++;
            }
            
            else
            {
                last_board = main_board;
                //get the move command in ui and pass it to movepiece
                std::string move;
                main_board.movePiece(move);
            }

            if (main_board.turn != last_board.turn)
            {
                dif = main_board.player[0].get_positive_score() - last_board.player[0].get_positive_score();
                main_board.player[0].add_positive_score(-dif);
                main_board.turn = Chessman::color_::White;
                i++;
            }
            main_board.turn = Chessman::color_::White;
        }

        main_board.turn = Chessman::color_::Black;
    }

    else if (main_board.turn == Chessman::color_::Black)
    {
        main_board.player[1].add_positive_score(-30);

        for (size_t i = 0; i < 2;)
        {
            //getting move command in ui and pass it to movepiece 
            if (main_board.turn == Chessman::color_::Black && main_board.player[1].get_negative_score() >= 15)
            {
                move = main_board.random_move();
                last_board = main_board; 
                main_board.movePiece(move);
                main_board.turn = Chessman::color_::White;
                main_board.player[1].add_positive_score(-15);
                i++;
            }
            else
            {
                last_board = main_board;
                
                //get the move command in ui and pass it to movepiece
                std::string move;
                main_board.movePiece(move);
            }
            if (main_board.turn != last_board.turn)
            {
                dif = main_board.player[1].get_positive_score() - last_board.player[1].get_positive_score();
                main_board.player[1].add_positive_score(-dif);
                main_board.turn = Chessman::color_::Black;
                i++;
            }
            main_board.turn = Chessman::color_::Black;
        }
        main_board.turn = Chessman::color_::White;
    }
        
    is_extra_move = false;
}

void Game::set_name(std::string name)
{
    game_name = name;
}

std::string Game::get_name()
{
    return game_name;
}
