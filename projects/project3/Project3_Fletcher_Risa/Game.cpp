/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Game class
*******************************************************************************/
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <memory>
#include <limits>

using std::make_shared;
using std::shared_ptr;

Game::Game()
{
    round = 0;
    playAgain = true;
}

int Game::getValidInt(int size)
{
    int selectedOption;
    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (std::cin >> selectedOption &&
            selectedOption < size + 1 &&
            selectedOption != 0)
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return selectedOption - 1;
}

void Game::printStats(shared_ptr<Character> offense, shared_ptr<Character> defense)
{
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << " " << defense->getType();
    std::cout << " (" << defense->getName() << ")" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << " Attack: " << defense->getAttackNumDie() << "d";
    std::cout << defense->getAttackNumSides() << std::endl;
    std::cout << " Defense: " << defense->getDefenseNumDie() << "d";
    std::cout << defense->getDefenseNumSides() << std::endl;
    std::cout << " Armor: " << defense->getArmor() << std::endl;
    std::cout << " Strength: " << defense->getStrengthPoints() << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "\n" << std::endl;
}

void Game::playTurn(shared_ptr<Character> offense, shared_ptr<Character> defense)
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "    " << offense->getType();
    std::cout << " vs. " << defense->getType() << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;
    int attackPoints = offense->attackPlayer();
    std::cout << " Attack roll: " << attackPoints << std::endl;
    int defensePoints = defense->defendPlayer();
    std::cout << " Defense roll: " << defensePoints << std::endl;
    defense->damage(attackPoints, defensePoints);
    printStats(offense, defense);
}

void Game::playTest()
{
    std::string name = "Test Character";
    shared_ptr<Character> fighters[NUMBER_OF_FIGHTERS] = {
        make_shared<Vampire>(name),
        make_shared<Barbarian>(name),
        make_shared<BlueMen>(name),
        make_shared<Medusa>(name),
        make_shared<HarryPotter>(name)
    };
    
    for (int i = 0; i < NUMBER_OF_FIGHTERS; ++i)
    {
        shared_ptr<Character> character = fighters[i];
        std::cout << "------------------------------" << std::endl;
        std::cout << "          " << character->getType() << "            " << std::endl;
        std::cout << "------------------------------" << std::endl;
        int attackPoints = character->attackPlayer();
        std::cout << " Attack roll: " << attackPoints << std::endl;
        int defensePoints = character->defendPlayer();
        std::cout << " Defense roll: " << defensePoints << std::endl;
        std::cout << std::endl;
    }
}

void Game::start()
{
    std::cout << "Welcome to Fantasy Combat Game\n" << std::endl;

    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Test Game" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int choice = getValidInt(3) + 1;

    switch(choice)
    {
        case 1:
            playGame();
            break;
        case 2:
            playTest();
            break;
        default:
            break;
    }
}

void Game::playGame()
{
    character1 = selectFighter("Player 1");
    character2 = selectFighter("Player 2");

    while(playAgain)
    {
        round++;
        std::cout << "------------------------------" << std::endl;
        std::cout << "|          ROUND " << round << "           |" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << std::endl;

        playTurn(character1, character2);

        if (character2->getStrengthPoints() == 0)
        {
            gameOver(character2);
            playAgain = false;
            break;
        }

        playTurn(character2, character1);

        if (character1->getStrengthPoints() == 0)
        {
            gameOver(character1);
            playAgain = false;
            break;
        }
    }
}

shared_ptr<Character> Game::selectFighter(string name)
{
    shared_ptr<Character> fighters[NUMBER_OF_FIGHTERS] = {
        make_shared<Vampire>(name),
        make_shared<Barbarian>(name),
        make_shared<BlueMen>(name),
        make_shared<Medusa>(name),
        make_shared<HarryPotter>(name)
    };

    std::cout << name << ", please select your fighter: " << std::endl;
    for (int i = 0; i < NUMBER_OF_FIGHTERS; ++i)
    {
        std::cout << i + 1 << ". " << fighters[i]->getType() << " - ";
        std::cout << fighters[i]->getCharacteristic() << "\n" << std::endl;
    }

    int selectedFighterIndex = getValidInt(NUMBER_OF_FIGHTERS);

    return fighters[selectedFighterIndex];
}

void Game::gameOver(shared_ptr<Character> loser)
{
    std::cout << loser->getName() << " lost." << std::endl;
    std::cout << "Game over." << std::endl;
}
