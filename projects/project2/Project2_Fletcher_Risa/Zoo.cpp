/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for the Zoo class. It contains data to keep
**               track of the bank and animals as well as methods for various
**               random events that occur at the zoo.
*******************************************************************************/
#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*********************************************************************
    ** Description: CONSTRUCTOR
*********************************************************************/
Zoo::Zoo()
{
    bankBalance = 100000;
    numberOfTigers = 0;
    numberOfPenguins = 0;
    numberOfTurtles = 0;
    dailyPayoff = 0;
    tigerCapacity = ANIMAL_CAPACITY;
    penguinCapacity = ANIMAL_CAPACITY;
    turtleCapacity = ANIMAL_CAPACITY;

    tigers = new Tiger[ANIMAL_CAPACITY];
    penguins = new Penguin[ANIMAL_CAPACITY];
    turtles = new Turtle[ANIMAL_CAPACITY];
}

/*********************************************************************
    ** Description: DESTRUCTOR
*********************************************************************/
Zoo::~Zoo()
{
    delete[] tigers;
    delete[] penguins;
    delete[] turtles;

    tigers = nullptr;
    penguins = nullptr;
    turtles = nullptr;
}

/*********************************************************************
    ** Description: Updates the bank balance. Receives a pos/neg
    **              value according to the addition or deduction
*********************************************************************/
void Zoo::updateBankBalance(int value)
{
    std::cout << "Bank transaction: " << bankBalance << " + ";
    std::cout << value << "\n" << std::endl;
    bankBalance += value;
}

/*********************************************************************
    ** Description: expands the animal capacity by creating a new
    **              array, copying the new values to the new array
    **              then pointing the old array to the new one
*********************************************************************/
void Zoo::expandAnimalCapacity(Animal *oldArray, int &oldCapacity, int currentNumberOfAnimals)
{
    std::cout << "Expanding array....\n" << std::endl;
    int newArrayCapacity = oldCapacity + ANIMAL_CAPACITY;
    Animal *newAnimalArray = new Animal[newArrayCapacity];
    for (int i = 0; i < currentNumberOfAnimals; ++i)
        newAnimalArray[i] = oldArray[i];
    delete[] oldArray;
    oldArray = newAnimalArray;
    oldCapacity = newArrayCapacity;
}

/*********************************************************************
    ** Description: adds an animal to the array. the user can specify
    **              whether this is a puchase transaction or not.
*********************************************************************/
void Zoo::addAnimal(AnimalType animalType, int age, bool isPurchase = false)
{
    switch (animalType)
    {
        case TIGER:
        {
            Tiger newTiger = Tiger(age);
            if (numberOfTigers == tigerCapacity)
                expandAnimalCapacity(tigers, tigerCapacity, numberOfTigers);
            tigers[numberOfTigers] = newTiger;
            numberOfTigers++;
            std::cout << "Tiger added.\n" << std::endl;
            if (isPurchase)
                updateBankBalance(-newTiger.getCost());
            break;
        }
        case PENGUIN:
        {
            Penguin newPenguin = Penguin(age);
            if (numberOfPenguins == penguinCapacity)
                expandAnimalCapacity(penguins, penguinCapacity, numberOfPenguins);
            penguins[numberOfPenguins] = newPenguin;
            numberOfPenguins++;
            std::cout << "Penguin added.\n" << std::endl;
            if (isPurchase)
                updateBankBalance(-newPenguin.getCost());
            break;
        }
        case TURTLE:
        {
            Turtle newTurtle = Turtle(age);
            if (numberOfTurtles == turtleCapacity)
                expandAnimalCapacity(turtles, turtleCapacity, numberOfTurtles);
            turtles[numberOfTurtles] = newTurtle;
            numberOfTurtles++;
            std::cout << "Turtle added.\n" << std::endl;
            if (isPurchase)
                updateBankBalance(-newTurtle.getCost());
            break;
        }
        default:
            break;
        }
}

/*********************************************************************
    ** Description: getter for the payoff amount
*********************************************************************/
int Zoo::getDailyPayoff()
{
    for (int i = 0; i < numberOfTigers; ++i)
        dailyPayoff += tigers[i].getPayoff();
    for (int i = 0; i < numberOfPenguins; ++i)
        dailyPayoff += penguins[i].getPayoff();
    for (int i = 0; i < numberOfTurtles; ++i)
        dailyPayoff += turtles[i].getPayoff();
    return dailyPayoff;
}

/*********************************************************************
    ** Description: A random event--a random value between 250-500
    **              is selected and applied to the daily payoff for 
    **              each tiger
*********************************************************************/
void Zoo::addBonus()
{
    int randomBonusAmount = rand() % 500 + 250;
    cout << "Business has been good. You've received " << randomBonusAmount
         << " for each tiger.\n" << endl;
    for (int i = 0; i < numberOfTigers; ++i)
        dailyPayoff += randomBonusAmount;
}

/*********************************************************************
    ** Description: resets the daily payoff amount
*********************************************************************/
void Zoo::resetPayoff()
{
    dailyPayoff = 0;
}

/*********************************************************************
    ** Description: checks each animal in the array to see if there
    **              are adult animals present
*********************************************************************/
bool Zoo::hasAdultAnimal()
{
    bool hasAdult = false;

    while (!hasAdult)
    {
        for (int i = 0; i < numberOfTigers; ++i)
            hasAdult = tigers[i].isAdult();
        for (int j = 0; j < numberOfPenguins; ++j)
            hasAdult = penguins[j].isAdult();
        for (int k = 0; k < numberOfTurtles; ++k)
            hasAdult = turtles[k].isAdult();
    }

    return hasAdult;
}

/*********************************************************************
    ** Description: returns a randum AnimalType enum
*********************************************************************/
AnimalType Zoo::getRandomAnimalType()
{
    return static_cast<AnimalType>(rand() % numberOfAnimalTypes);
}

/*********************************************************************
    ** Description: a random animal births babies if there are
    **              adult animals available to give birth
*********************************************************************/
void Zoo::birthBaby()
{   
    if (hasAdultAnimal())
    {
        const string animalNames[] = {"tiger", "penguin", "turtle"};
        int randomAnimalType = getRandomAnimalType();
        switch (randomAnimalType)
        {
            case TIGER:
            {
                if (numberOfTigers == 0)
                    birthBaby();
                else
                {                    
                    Tiger randomTiger = tigers[rand() % numberOfTigers];
                    if (randomTiger.isAdult())
                    {
                        for (int i = 0; i < randomTiger.getNumberOfBabies(); ++i)
                            addAnimal(TIGER, 0);
                        cout << "Congratulations! One of your tigers has given birth!\n" << endl;
                    }
                    else
                        birthBaby();
                }
                break;
            }
            case PENGUIN:
            {
                if (numberOfPenguins == 0)
                    birthBaby();
                else
                {      
                    Penguin randomPenguin = penguins[rand() % numberOfPenguins];
                    if (randomPenguin.isAdult())
                    {
                        for (int i = 0; i < randomPenguin.getNumberOfBabies(); ++i)
                            addAnimal(PENGUIN, 0);
                        cout << "Congratulations! One of your penguins has given birth!\n" << endl;
                    }
                    else
                        birthBaby();
                }
                break;
            }
            case TURTLE:
            {   
                if (numberOfTurtles == 0)
                    birthBaby();
                else
                {    
                    Turtle randomTurtle = turtles[rand() % numberOfTurtles];
                    if (randomTurtle.isAdult())
                    {
                        for (int i = 0; i < randomTurtle.getNumberOfBabies(); ++i)
                            addAnimal(TURTLE, 0);
                        cout << "Congratulations! One of your turtles has given birth!\n" << endl;
                    }
                    else
                        birthBaby();
                }
                
                break;
            }
            default:
                break;
        }
    }
}

/*********************************************************************
    ** Description: removes an animal from the array
*********************************************************************/
void Zoo::removeAnimal(Animal *animals, int capacity, int &numberOfAnimals)
{
    int randomIndex = rand() % numberOfAnimals;
    Animal *newArray = new Animal[capacity];
    for (int i = 0; i < numberOfAnimals; ++i)
    {
        if (i != randomIndex)
        {
            // once we've skipped over the random element
            // each element should now be added to the new array
            // by shifting it down to account for the missing element
            if (i > randomIndex)
                newArray[i - 1] = animals[i];
            else
                newArray[i] = animals[i];
        }
    }
    delete[] animals;
    animals = newArray;
    numberOfAnimals--;
}

/*********************************************************************
    ** Description: kills a random animal
*********************************************************************/
void Zoo::killAnimal()
{
    AnimalType animalType = getRandomAnimalType();
    switch (animalType)
    {
        case TIGER:
            if (numberOfTigers > 0)
            {
                std::cout << "A tiger has fallen ill and passed away. :( ";
                std::cout << "You now have " << numberOfTigers - 1 << " remaining tigers.\n" << std::endl;
                removeAnimal(tigers, tigerCapacity, numberOfTigers);
            }
            else
            {
                killAnimal();
            }
            break;
        case PENGUIN:
            if (numberOfPenguins > 0)
            {
                std::cout << "A penguin has fallen ill and passed away. :( ";
                std::cout << "You now have " << numberOfPenguins - 1 << " remaining penguins.\n" << std::endl;
                removeAnimal(penguins, penguinCapacity, numberOfPenguins);
            }
            else
            {
                killAnimal();
            }
            break;
        case TURTLE:
            if (numberOfTurtles > 0)
            {
                std::cout << "A turtle has fallen ill and passed away. :( ";
                std::cout << "You now have " << numberOfTurtles - 1 << " remaining turtles.\n" << std::endl;
                removeAnimal(turtles, turtleCapacity, numberOfTurtles);
            }
            else
            {
                killAnimal();
            }
            break;
        default:
            break;
    }
}

/*********************************************************************
    ** Description: ages each animal for the day
*********************************************************************/
void Zoo::incrementAnimalAges()
{
    for (int i = 0; i < numberOfTigers; ++i)
        tigers[i].incrementAge();
    for (int i = 0; i < numberOfPenguins; ++i)
        penguins[i].incrementAge();
    for (int i = 0; i < numberOfTurtles; ++i)
        turtles[i].incrementAge();
}

/*********************************************************************
    ** Description: generates a random event for the day:
    **              kill a random animal, birth new animals, or add
    **              a bonus to the day's payoff
*********************************************************************/
void Zoo::generateRandomEvent()
{
    int randomEventInt = rand() % 3;
    switch(randomEventInt)
    {
        case 0:
            killAnimal();
            break;
        case 1:
            addBonus();
            break;
        case 2:
            birthBaby();
            break;
        default:
            break;
    }
}

/*********************************************************************
    ** Description: prints the daily stats
*********************************************************************/
void Zoo::printDailyStats()
{
    std::cout << "-----------------" << std::endl;
    std::cout << "Today's stats: " << std::endl;
    std::cout << "PAYOFF: " << dailyPayoff << std::endl;
    std::cout << "Number of tigers: " << numberOfTigers << std::endl;
    std::cout << "Number of penguins: " << numberOfPenguins << std::endl;
    std::cout << "Number of turtles: " << numberOfTurtles << std::endl;
    std::cout << "BANK BALANCE: " << bankBalance << std::endl;
    std::cout << "-----------------" << std::endl;
}

/*********************************************************************
    ** Description: getter for the bank balance
*********************************************************************/
int Zoo::getBankBalance()
{
    return bankBalance;
}

/*********************************************************************
    ** Description: feeds the animals each day and deducts the costs
    **              from the bank
*********************************************************************/
void Zoo::feedAnimals()
{
    int foodCost = 0;
    for (int i = 0; i < numberOfTigers; ++i)
        foodCost += tigers[i].getFoodCost();
    for (int i = 0; i < numberOfPenguins; ++i)
        foodCost += penguins[i].getFoodCost();
    for (int i = 0; i < numberOfTurtles; ++i)
        foodCost += turtles[i].getFoodCost();

    std::cout << "Total food cost: " << foodCost << std::endl;
    updateBankBalance(-foodCost);
}