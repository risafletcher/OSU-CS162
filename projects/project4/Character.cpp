/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Character class (abstract)
*******************************************************************************/
#include "Character.hpp"
#include <string>
#include <iostream>

/*********************************************************************
    ** Description: GETTERS
*********************************************************************/
int Character::getStrengthPoints()
{
    return strengthPoints;
}

int Character::getArmor()
{
    return armor;
}

string Character::getName()
{
    return name;
}

string Character::getType()
{
    return type;
}

int Character::getAttackNumDie()
{
    return attack.numberOfDie;
}

int Character::getDefenseNumDie()
{
    return defense.numberOfDie;
}

int Character::getAttackNumSides()
{
    return attack.numberOfSides;
}

int Character::getDefenseNumSides()
{
    return defense.numberOfSides;
}

string Character::getCharacteristic()
{
    return characteristic;
}

/*********************************************************************
    ** Description: SETTERS
*********************************************************************/
void Character::setName(string name)
{
    this->name = name;
}

/*********************************************************************
    ** Description: rolls a dice with X number of sides and Y times 
    **              to produce the attack or defense total
*********************************************************************/
int Character::roll(Die dice)
{
    int total = 0;
    for (int i = 0; i < dice.numberOfDie; ++i)
        total += std::rand() % dice.numberOfSides + 1;
    return total;
}

/*********************************************************************
    ** Description: calculates total attack points
*********************************************************************/
int Character::attackPlayer()
{
    return roll(this->attack);
}

/*********************************************************************
    ** Description: calculates total defense points
*********************************************************************/
int Character::defendPlayer()
{
    return roll(this->defense);
}

/*********************************************************************
    ** Description: takes in damage points and applies them to 
    **              character
*********************************************************************/
void Character::damage(int attackRoll, int defenseRoll)
{
    int total = attackRoll - defenseRoll - armor;
    if (total >= 0)
    {
        std::cout << " Actual damage inflicted: " << total << std::endl;
        strengthPoints -= total;

    }
    else
        strengthPoints = 0;
}

void Character::restoreSomeHp()
{
    int strengthPointsMissing = this->MAX_STRENGTH_POINTS - this->strengthPoints;
    if (strengthPointsMissing > 0)
    {
        int restoredHp = std::rand() % strengthPointsMissing;
        this->strengthPoints += restoredHp;
        std::cout << this->name << " restored " << restoredHp;
        std::cout << " strength points from winning." << std::endl;
    }
}
