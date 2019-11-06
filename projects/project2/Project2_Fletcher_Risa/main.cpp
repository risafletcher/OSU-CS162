/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/30/19
** Description:  A game for Zoo Tycoon.
*******************************************************************************/
#include "Animal.hpp"
#include "Game.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Zoo.hpp"

int main()
{
    Game game;
    Zoo zoo;

    game.start(zoo);

    return 0;
}