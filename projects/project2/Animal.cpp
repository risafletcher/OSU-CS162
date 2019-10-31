/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a zoo Animal class
*******************************************************************************/
#include "Animal.hpp"

Animal::Animal(int age, int cost, int numberOfBabies, int baseFoodCost)
{
    this->age = age;
    this->cost = cost;
    this->numberOfBabies = numberOfBabies;
    setBaseFoodCost(baseFoodCost);
}

bool Animal::isAdult()
{
    return age >= 3;
}

void Animal::setBaseFoodCost(int baseFoodCost)
{
    this->baseFoodCost = baseFoodCost;
}

void Animal::setPayoffRate(int payoff)
{
    this->payoff = payoff;
}

void Animal::incrementAge()
{
    age++;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getPayoff()
{
    return payoff;
}

int Animal::getNumberOfBabies()
{
    return numberOfBabies;
}
