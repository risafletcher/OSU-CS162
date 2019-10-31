/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for the Zoo class. It contains data to keep
**               track of the bank and animals as well as methods for various
**               random events that occur at the zoo.
*******************************************************************************/
#include "Zoo.hpp";
#include "Tiger.hpp";
#include "Penguin.hpp";
#include "Turtle.hpp";
#include <iostream>;
#include <string>;

using std::cout;
using std::endl;
using std::string;

Zoo::Zoo()
{
    this->bankBalance = 100000;
    this->numberOfTigers = 0;
    this->numberOfPenguins = 0;
    this->numberOfTurtles = 0;
    this->tigerCapacity = ANIMAL_CAPACITY;
    this->penguinCapacity = ANIMAL_CAPACITY;
    this->turtleCapacity = ANIMAL_CAPACITY;

    tigers = new Tiger[ANIMAL_CAPACITY];
    penguins = new Penguin[ANIMAL_CAPACITY];
    turtles = new Turtle[ANIMAL_CAPACITY];
}

Zoo::~Zoo()
{
    delete[] tigers;
    delete[] penguins;
    delete[] turtles;

    tigers = nullptr;
    penguins = nullptr;
    turtles = nullptr;
}

void Zoo::updateBankBalance(int value)
{
    bankBalance += value;
}

void Zoo::expandAnimalCapacity(Animal *oldArray, int &oldCapacity, int currentNumberOfAnimals)
{
    int newArrayCapacity = oldCapacity + ANIMAL_CAPACITY;
    Animal *newAnimalArray = new Animal[newArrayCapacity];
    for (int i = 0; i < currentNumberOfAnimals; ++i)
        newAnimalArray[i] = oldArray[i];
    oldArray = newAnimalArray;
    oldCapacity = newArrayCapacity;
    delete[] newAnimalArray;
    newAnimalArray = nullptr;
}

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
            if (isPurchase)
                updateBankBalance(-newTurtle.getCost());
            break;
        }
        default:
            break;
        }
}

int Zoo::getDailyPayoff()
{
    for (int i = 0; i < numberOfTigers; i++)
        this->dailyPayoff += tigers[i].getPayoff();
    for (int i = 0; i < numberOfPenguins; i++)
        this->dailyPayoff += penguins[i].getPayoff();
    for (int i = 0; i < numberOfTurtles; i++)
        this->dailyPayoff += turtles[i].getPayoff();
    return this->dailyPayoff;
}

void Zoo::addBonus()
{
    int randomBonusAmount = rand() % 500 + 250;
    cout << "Business has been good. You've received " << randomBonusAmount
         << " for each tiger." << endl;
    for (int i = 0; i < numberOfTigers; ++i)
        dailyPayoff += randomBonusAmount;
}

void Zoo::resetPayoff()
{
    dailyPayoff = 0;
}

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

AnimalType Zoo::getRandomAnimalType()
{
    return static_cast<AnimalType>(rand() % numberOfAnimalTypes);
}

void Zoo::birthBaby()
{   
    if (hasAdultAnimal())
    {
        const string animalNames[] = {"tiger", "penguin", "turtle"};
        int randomAnimalType = getRandomAnimalType();
        switch (randomAnimalType)
        {
            case TIGER:
                Tiger randomTiger = tigers[rand() % numberOfTigers];
                if (randomTiger.isAdult())
                {
                    for (int i = 0; i < randomTiger.getNumberOfBabies(); ++i)
                        addAnimal(TIGER, 0);
                }
                else
                    birthBaby();
                break;
            case PENGUIN:
                Penguin randomPenguin = penguins[rand() % numberOfPenguins];
                if (randomPenguin.isAdult())
                {
                    for (int i = 0; i < randomPenguin.getNumberOfBabies(); ++i)
                        addAnimal(PENGUIN, 0);
                }
                else
                    birthBaby();
                break;
            case TURTLE:
                Turtle randomTurtle = turtles[rand() % numberOfTurtles];
                if (randomTurtle.isAdult())
                {
                    for (int i = 0; i < randomTurtle.getNumberOfBabies(); ++i)
                        addAnimal(TURTLE, 0);
                }
                else
                    birthBaby();
                break;
            default:
                break;
        }

        cout << "Congratulations! One of your " << animalNames[randomAnimalType]
             << " has given birth!" << endl;
    }
}

void Zoo::removeAnimal(Animal *animals, int capacity, int &numberOfAnimals)
{
    int randomIndex = rand() % numberOfAnimals;
    Animal *newArray = new Animal[capacity];
    for (int i = 0; i < numberOfAnimals; ++i)
    {
        if (i != randomIndex)
        {
            if (i > randomIndex)
                newArray[i - 1] = animals[i];
            else
                newArray[i] = animals[i];
        }
    }
    animals = newArray;
    delete[] newArray;
    newArray = nullptr;
    numberOfAnimals--;
}

void Zoo::killAnimal()
{
    AnimalType animalType = getRandomAnimalType();
    switch (animalType)
    {
        case TIGER:
            if (numberOfTigers > 0)
            {
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

void Zoo::incrementAnimalAges()
{
    for (int i = 0; i < numberOfTigers; ++i)
        tigers[i].incrementAge();
    for (int i = 0; i < numberOfPenguins; ++i)
        penguins[i].incrementAge();
    for (int i = 0; i < numberOfTurtles; ++i)
        turtles[i].incrementAge();
}