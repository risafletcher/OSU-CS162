/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Fantasy combat game involving random die and special abilities.
*******************************************************************************/
#include "Game.hpp"
#include <iostream>

int main()
{
    bool playAgain = true;

    Game game;

    game.start();

    while (playAgain)
    {
        std::cout << "\n1. Play Again?" << std::endl;
        std::cout << "2. Exit" << std::endl;

        int choice = game.getValidInt(3) + 1;

        if (choice == 1)
        {
            Game newGame;
            newGame.playGame();
        }
        else
        {
            playAgain = false;
        }
    }
    return 0;
}