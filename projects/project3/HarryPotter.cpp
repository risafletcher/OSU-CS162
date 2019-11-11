/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for HarryPotter, a derived Character class
*******************************************************************************/
#include "HarryPotter.hpp"
#include <iostream>

HarryPotter::HarryPotter()
{
    type = "Harry Potter";
    this->attack = {2, 6};
    this->defense = {2, 6};
    armor = 0;
    strengthPoints = 10;
    hasBeenRevived = false;
}

HarryPotter::HarryPotter(string name) : HarryPotter()
{
    setName(name);
}

void HarryPotter::damage(int attackRoll, int defenseRoll)
{
    int total = attackRoll - defenseRoll - armor;
    if (attackRoll == 200 && !hasBeenRevived)
    {
        std::cout << "Harry has recovered from Medusa's glare." << std::endl;
        strengthPoints = 20;
        hasBeenRevived = true;
    }
    else if (total >= 0)
    {
        std::cout << " Actual damage inflicted: " << total << std::endl;
        strengthPoints -= total;
    }
    else
        strengthPoints = 0;
    
    if (strengthPoints == 0 && !hasBeenRevived)
    {
        std::cout << " Harry has been revived. He has 1 life remaining." << std::endl;
        strengthPoints = 20;
        hasBeenRevived = true;
    }
}
