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
}

BlueMen::BlueMen(string name) : BlueMen()
{
    setName(name);
}

void BlueMen::mob()
{
 
}

void BlueMen::damage(int attackRoll, int defenseRoll)
{
    int prevStrength = strengthPoints;
    Character::damage(attackRoll, defenseRoll);
    int currentStrength = strengthPoints;
    int difference = prevStrength - currentStrength;
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