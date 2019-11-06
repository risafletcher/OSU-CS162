/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a zoo Animal class
*******************************************************************************/
#include "Animal.hpp"

Animal::Animal()
{}

/*********************************************************************
    ** Description: CONSTRUCTOR
*********************************************************************/
Animal::Animal(int age, int cost, int numberOfBabies, int baseFoodCost)
{
    this->age = age;
    this->cost = cost;
    this->numberOfBabies = numberOfBabies;
    setBaseFoodCost(baseFoodCost);
}

/*********************************************************************
    ** Description: returns true if the animal is an adult
*********************************************************************/
bool Animal::isAdult()
{
    return age >= 3;
}

/*********************************************************************
    ** Description: increments age for each day
*********************************************************************/
void Animal::incrementAge()
{
    age++;
}

/*********************************************************************
    ** Description: SETTERS
*********************************************************************/
void Animal::setBaseFoodCost(int baseFoodCost)
{
    this->foodCost = baseFoodCost;
}

void Animal::setPayoffRate(int payoff)
{
    this->payoff = payoff;
}


/*********************************************************************
    ** Description: GETTERS
*********************************************************************/
int Animal::getCost()
{
    return this->cost;
}

int Animal::getPayoff()
{
    return this->payoff;
}

int Animal::getNumberOfBabies()
{
    return this->numberOfBabies;
}

int Animal::getFoodCost()
{
    return this->foodCost;
}
