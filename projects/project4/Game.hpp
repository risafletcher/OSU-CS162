/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for Game class
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Lineup.hpp"
#include "Losers.hpp"
#include <memory>

using std::shared_ptr;

class Game
{
    private:
        int round;
        int teamSize;
        shared_ptr<Lineup> team1;
        shared_ptr<Lineup> team2;
        shared_ptr<Losers> losers;
        const int NUMBER_OF_FIGHTERS = 5;

    public:
        Game();
        int getValidInt(int);
        shared_ptr<Character> selectFighter(string);
        void selectFighters(shared_ptr<Lineup>);
        void start(),
            playGame(),
            playRound(),
            playTest(),
            playTurn(shared_ptr<Character>, shared_ptr<Character>),
            printStats(shared_ptr<Character>, shared_ptr<Character>),
            defeatCharacter(shared_ptr<Character>, shared_ptr<Lineup>),
            succeedCharacter(shared_ptr<Character>, shared_ptr<Lineup>),
            gameOver();
};

#endif