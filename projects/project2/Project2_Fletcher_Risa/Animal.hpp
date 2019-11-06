/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for a zoo Animal class
*******************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
    protected:
        int age,
            cost,
            numberOfBabies,
            foodCost = 10,
            payoff;

    public:
        Animal();
        Animal(int age, int cost, int numberOfBabies, int baseFoodCost);
        int getCost();
        int getPayoff();
        int getNumberOfBabies();
        int getFoodCost();
        bool isAdult();
        void setBaseFoodCost(int cost);
        void setPayoffRate(int paymentPerDay);
        void incrementAge();
};

#endif