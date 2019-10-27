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
    int firstRoll = randomInt();
    int secondRoll = randomInt();
    int thirdRoll = randomInt();
    int greatestValue;

    if (firstRoll > secondRoll && firstRoll > thirdRoll)
        greatestValue = firstRoll;
    if (secondRoll > firstRoll && secondRoll > thirdRoll)
        greatestValue = secondRoll;
    if (thirdRoll > firstRoll && thirdRoll > secondRoll)
        greatestValue = thirdRoll;

    return greatestValue;
}