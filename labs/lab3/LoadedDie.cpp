/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Die class that accepts a number of sides for a die and 
**               provides a method that returns an int higher than a regular
**               Die object.
*******************************************************************************/
#include "LoadedDie.hpp"
#include <iostream>

LoadedDie::LoadedDie(int n)
{
    this->n = n;
}

int LoadedDie::roll()
{
    int firstRoll = std::rand() % n + 1;
    int secondRoll = std::rand() % n + 1;

    if (firstRoll > secondRoll)
        return firstRoll;
    else
        return secondRoll;
}