/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a Turtle Animal class, which derives
**               from the Animal class
*******************************************************************************/
#include "Turtle.hpp"

/*********************************************************************
    ** Description: CONSTRUCTORS
*********************************************************************/
Turtle::Turtle()
{
    this->cost = 100;
    this->numberOfBabies = 10;
    this->foodCost = 0.5 * this->foodCost;
    this->payoff = 0.05 * cost;
}

Turtle::Turtle(int age)
{
    this->cost = 100;
    this->numberOfBabies = 10;
    this->foodCost = 0.5 * this->foodCost;
    this->payoff = 0.05 * cost;
    this->age = age;
    Turtle();
}