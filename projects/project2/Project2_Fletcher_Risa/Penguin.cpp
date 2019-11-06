/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a Penguin Animal class, which derives
**               from the Animal class
*******************************************************************************/
#include "Penguin.hpp"

/*********************************************************************
    ** Description: CONSTRUCTORS
*********************************************************************/
Penguin::Penguin()
{
    this->cost = 1000;
    this->numberOfBabies = 5;
    this->payoff = 0.1 * cost;
}

Penguin::Penguin(int age)
{
    this->cost = 1000;
    this->numberOfBabies = 5;
    this->payoff = 0.1 * cost;
    this->age = age;
    Penguin();
}