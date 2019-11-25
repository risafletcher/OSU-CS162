/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Medusa, a derived Character class
*******************************************************************************/
#include "Medusa.hpp"
#include "Character.hpp"
#include <iostream>

Medusa::Medusa()
{
    type = "Medusa";
    this->attack = {2, 6};
    this->defense = {1, 6};
    armor = 3;
    strengthPoints = 8;
    this->MAX_STRENGTH_POINTS = 8;
    characteristic = "Scrawny lady with snakes for hair which helps her "
                     "during combat. Just don’t look at her!";
}

Medusa::Medusa(string name) : Medusa()
{
    setName(name);
}

int Medusa::attackPlayer()
{
    int attackRoll = Character::attackPlayer();
    if (attackRoll == 12)
    {
        std::cout << "Medusa has turned the target to stone!" << std::endl;
        attackRoll = 200;
    }

    return attackRoll;
}
