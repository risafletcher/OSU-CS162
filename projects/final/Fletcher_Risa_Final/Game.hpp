/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A class for the game itself
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Bathroom.hpp"
#include "Dining.hpp"
#include "Hall.hpp"
#include "Library.hpp"
#include "Reception.hpp"
#include "Stairwell.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Game
{
    string directions[5] = {
        "North",
        "East",
        "South",
        "West",
        "Exit"};

    private:
        int steps;
        Bathroom *bathroom;
        Dining *dining;
        Hall *hall;
        Library *library;
        Reception *reception;
        Stairwell *stairwell;
        Space *currentLocation;
        Player *player;
        string getLabel(Space *);

    public:
        Game();
        ~Game();
        void play();
        string locationMenu();
        bool canMove(int);
};

#endif