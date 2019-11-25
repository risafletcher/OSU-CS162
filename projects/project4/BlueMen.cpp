/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for BlueMen, a derived Character class
*******************************************************************************/
#include "BlueMen.hpp"
#include "Character.hpp"
#include <iostream>

BlueMen::BlueMen()
{
    type = "Blue Men";
    this->attack = {2, 10};
    this->defense = {3, 6};
    armor = 3;
    strengthPoints = 12;
    this->MAX_STRENGTH_POINTS = 12;
    characteristic = "They are small, 6 inch tall, but fast and tough. They "
                     "are hard to hit so they can take some damage. They can also do a LOT of "
                     "damage when they crawl inside enemies’ armor or clothing.";
}

BlueMen::BlueMen(string name) : BlueMen()
{
    setName(name);
}

void BlueMen::damage(int attackRoll, int defenseRoll)
{
    // keep track of current strength points
    int prevStrength = strengthPoints;
    // proceed to invoke the base damage method
    Character::damage(attackRoll, defenseRoll);
    // compare the new strength points to the old value
    int currentStrength = strengthPoints;
    int difference = prevStrength - currentStrength;
    // if the difference is divislbe by 4, check to see if there are
    // enough die to remove
    // else, remove all die
    if (difference >= 4)
    {
        int lostDie = difference / 4;
        int newDefenseNumDie = defense.numberOfDie - lostDie;
        if (newDefenseNumDie >= 0)
            defense.numberOfDie = newDefenseNumDie;
        else
            defense.numberOfDie = 0;
    }
}