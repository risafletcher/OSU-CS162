/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Vampire, a derived Character class
*******************************************************************************/
#include "Vampire.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

using std::string;

Vampire::Vampire()
{
    type = "Vampire";
    this->attack = {1, 12};
    this->defense = {1, 6};
    armor = 1;
    strengthPoints = 18;
    characteristic = "Suave, debonair, but vicious and surprisingly "
    "resilient.";
}

Vampire::Vampire(string name) : Vampire()
{
    setName(name);
}

bool Vampire::charm()
{
    // set new seed each time the function is run
    // source: https://stackoverflow.com/questions/5574914/srandtimenull-doesnt-change-seed-value-quick-enough
    srand(time(NULL));
    return (std::rand() % 2) != 0;
}

/*********************************************************************
    ** Description: takes in damage points and applies them to 
    **              character
*********************************************************************/
void Vampire::damage(int attackRoll, int defenseRoll)
{
    bool isCharmed = charm();
    if (isCharmed)
    {
        std::cout << name << " has charmed their way out of an attack!\n";
        std::cout << std::endl;
    }
    else
        Character::damage(attackRoll, defenseRoll);
}