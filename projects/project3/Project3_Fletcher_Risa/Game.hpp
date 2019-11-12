/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for Game class
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include <memory>

using std::shared_ptr;

class Game
{
    private:
        int round;
        shared_ptr<Character> character1;
        shared_ptr<Character> character2;
        bool playAgain;
        const int NUMBER_OF_FIGHTERS = 5;

    public:
        Game();
        int getValidInt(int);
        shared_ptr<Character> selectFighter(string);
        void start(),
            playGame(),
            playTest(),
            playTurn(shared_ptr<Character>, shared_ptr<Character>),
            printStats(shared_ptr<Character>, shared_ptr<Character>),
            playAgainMenu(),
            gameOver(shared_ptr<Character>);
};

#endif