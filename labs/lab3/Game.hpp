/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Game class that implements the dice-rolling war game.
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

class Game
{
    private:
        const int NUMBER_OF_PLAYERS = 2;
        bool shouldPlay = true;
        int numRounds = 0;
        bool isLoaded = false;
        void startMenu();
        void openMenu();
        Player players[2];

    public:
        void playGame();
};

#endif