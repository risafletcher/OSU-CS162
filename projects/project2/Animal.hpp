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
            foodCost,
            payOffRate;

        bool isAdult();
        void setFoodCost(int cost);
        void setPayOffRate(int paymentPerDay);
        void incrementAge();

    public:
        Animal(int age, int cost, int numberOfBabies, int foodCost);
};

#endif