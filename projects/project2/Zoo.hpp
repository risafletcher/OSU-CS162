/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for the Zoo class. It contains data to keep
**               track of the bank and animals as well as methods for various
**               random events that occur at the zoo.
*******************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp";
#include "Tiger.hpp";
#include "Penguin.hpp";
#include "Turtle.hpp";

enum Event { SICKNESS, BONUS, BIRTH };
enum AnimalType { TIGER, PENGUIN, TURTLE };

class Zoo
{
    private:
        const int ANIMAL_CAPACITY = 10;
        int bankBalance,
            dailyPayoff = 0,
            numberOfAnimalTypes = 3,
            numberOfTigers,
            tigerCapacity,
            numberOfPenguins,
            penguinCapacity,
            numberOfTurtles,
            turtleCapacity;
        Tiger *tigers;
        Penguin *penguins;
        Turtle *turtles;

    public:
        Zoo();
        ~Zoo();

        void updateBankBalance(int);
        void feedAnimals();
        void addAnimal(AnimalType, int, bool);
        void birthBaby();
        void killAnimal();
        void addBonus();
        void resetPayoff();
        int getDailyPayoff();
        bool hasAdultAnimal();
        void expandAnimalCapacity(Animal*, int&, int);
        void removeAnimal(Animal*, int, int&);
        void incrementAnimalAges();
        AnimalType getRandomAnimalType();
};

#endif