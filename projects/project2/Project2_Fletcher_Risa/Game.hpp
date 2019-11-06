/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for the Game class, which contains logic
**               for starting the game, menus, input validation, and general
**               game flow.
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "Zoo.hpp"

class Game
{
    private:
        int day;
    
    public:
        Game();
        bool playAgain();
        void buyAnimal(Zoo&);
        void start(Zoo&);
        int startMenu();
        void playTurn(Zoo&);
        void gameOver();
        int menu(std::string[], int);
};

#endif