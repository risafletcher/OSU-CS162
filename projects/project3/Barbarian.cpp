/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Barbarian, a derived Character class
*******************************************************************************/
#include "Barbarian.hpp"

Barbarian::Barbarian()
{
    type = "Barbarian";
    this->attack = {2, 6};
    this->defense = {2, 6};
    armor = 0;
    strengthPoints = 12;
}

Barbarian::Barbarian(string name) : Barbarian()
{
    setName(name);
}
