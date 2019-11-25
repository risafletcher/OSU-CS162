/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for Game class
*******************************************************************************/
#include "Game.hpp"
#include "Losers.hpp"
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
    team1 = make_shared<Lineup>();
    team2 = make_shared<Lineup>();
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

void Game::selectFighters(shared_ptr<Lineup> team)
{
    for (int i = 0; i < teamSize; ++i)
    {
        std::string name;
        std::cout << "Please enter a name for your fighter: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        shared_ptr<Character> newCharacter = selectFighter(name);
        team->addBack(newCharacter);
    }
}

void Game::playRound()
{
    round++;
    std::cout << "------------------------------" << std::endl;
    std::cout << "|          ROUND " << round << "           |" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;

    shared_ptr<Character> team1Player = team1->getFront();
    shared_ptr<Character> team2Player = team2->getFront();

    playTurn(team1Player, team2Player);
    if (team2Player->getStrengthPoints() <= 0)
    {
        succeedCharacter(team1Player, team1);
        defeatCharacter(team2Player, team2);
    }
    else
    {        
        playTurn(team2Player, team1Player);

        if (team1Player->getStrengthPoints() <= 0)
        {
            succeedCharacter(team2Player, team2);
            defeatCharacter(team1Player, team1);
        }
        else
        {
            team1->removeFront();
            team1->addBack(team1Player);
            team2->removeFront();
            team2->addBack(team2Player);
        }   
    }
    
    if (team1->isEmpty() || team2->isEmpty())
        gameOver();
    else
    {
        playRound();
    }
}

void Game::playGame()
{
    std::cout << "How many fighters on each team? ";
    teamSize = getValidInt(20) + 1;
    // initialize Losers stack
    losers = make_shared<Losers>(teamSize * 2);

    std::cout << "\n TEAM 1" << std::endl;
    std::cout << "------------------------------" << std::endl;
    selectFighters(team1);

    std::cout << "\n TEAM 2" << std::endl;
    std::cout << "------------------------------" << std::endl;
    selectFighters(team2);

    playRound();
}

void Game::succeedCharacter(shared_ptr<Character> character,
                            shared_ptr<Lineup> team)
{
    std::cout << character->getName() << " wins!" << std::endl;
    team->addPoints(2);
    character->restoreSomeHp();
    shared_ptr<Character> winner = character;
    team->removeFront();
    team->addBack(winner);
}

void Game::defeatCharacter( shared_ptr<Character> character,
                            shared_ptr<Lineup> team)
{
    std::cout << character->getName() << " has been sent to the loser pile." << std::endl;
    team->addPoints(-1);
    shared_ptr<Character> loser = character;
    losers->push(loser);
    losers->addQuantity(1);
    team->removeFront();
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

    std::cout << "Please select a fighter: " << std::endl;
    for (int i = 0; i < NUMBER_OF_FIGHTERS; ++i)
    {
        std::cout << i + 1 << ". " << fighters[i]->getType() << " - ";
        std::cout << fighters[i]->getCharacteristic() << "\n" << std::endl;
    }

    int selectedFighterIndex = getValidInt(NUMBER_OF_FIGHTERS);

    return fighters[selectedFighterIndex];
}

void Game::gameOver()
{
    std::cout << "\n\nGame over." << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Team 1 points: " << team1->getPoints() << std::endl;
    std::cout << "Team 2 points: " << team2->getPoints() << std::endl;
    std::cout << "\nWinning team: ";
    if (team1->getPoints() == team2->getPoints())
        std::cout << "TIE" << std::endl;
    else if (team1->getPoints() > team2->getPoints())
        std::cout << "Team 1" << std::endl;
    else if (team2->getPoints() > team1->getPoints())
        std::cout << "Team 2" << std::endl;
    std::cout << "\nShow loser pile?" << std::endl;
    std::cout << "1. Yes\n2. No" << std::endl;
    int choice = getValidInt(2);
    if (choice == 0)
        losers->printLosers();
}
