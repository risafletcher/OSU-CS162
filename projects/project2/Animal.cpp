/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for a zoo Animal class
*******************************************************************************/
#include "Animal.hpp"

Animal::Animal(int age, int cost, int numberOfBabies, int foodCost)
{
    this->age = age;
    this->cost = cost;
    this->numberOfBabies = numberOfBabies;
    setFoodCost(foodCost);
}

bool Animal::isAdult()
{
    return age >= 3;
}

void Animal::setFoodCost(int foodCost)
{
    this->foodCost = foodCost;
}

void Animal::setPayOffRate(int paymentPerDay)
{
    payOffRate = paymentPerDay;
}

void Animal::incrementAge()
{
    age++;
}
