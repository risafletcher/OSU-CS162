/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a Tiger Animal class, which derives
**               from the Animal class
*******************************************************************************/
#include "Tiger.hpp"

/*********************************************************************
    ** Description: CONSTRUCTORS
*********************************************************************/
Tiger::Tiger()
{
    this->cost = 10000;
    this->numberOfBabies = 1;
    this->foodCost = 5 * this->foodCost;
    this->payoff = 0.2 * cost;
}

Tiger::Tiger(int age)
{
    this->cost = 10000;
    this->numberOfBabies = 1;
    this->foodCost = 5 * this->foodCost;
    this->payoff = 0.2 * cost;
    this->age = age;
    Tiger();
}