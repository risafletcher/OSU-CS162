/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Implementation file for the Game class, which contains logic
**               for starting the game, menus, input validation, and general
**               game flow.
*******************************************************************************/
#include "Game.hpp"
#include "Zoo.hpp"
#include <iostream>
#include <limits>
#include <string>

Game::Game()
{
    this->day = 1;
}

/*********************************************************************
    ** Description: Starts the game by asking initial setup questions
    **              then plays turns as user agrees.
*********************************************************************/
void Game::start(Zoo &zoo)
{
    int choice = startMenu();
    bool playAgain = true;
    if (choice == 1)
        playAgain = false;

    std::cout << "Before we begin, please purchase 3 animals." << std::endl;
    std::string buyAnimalOptions[3] = {
        "Tiger",
        "Penguin",
        "Turtle"};
    for (int i = 0; i < 3; ++i)
    {
        int selectedOption = menu(buyAnimalOptions, 3);
        if (selectedOption == 0)
            zoo.addAnimal(TIGER, 1, true);
        if (selectedOption == 1)
            zoo.addAnimal(PENGUIN, 1, true);
        if (selectedOption == 2)
            zoo.addAnimal(TURTLE, 1, true);
    }


    while (playAgain)
    {
        playTurn(zoo);
        if (zoo.getBankBalance() > 0)
            playAgain = this->playAgain();
        else
        {
            std::cout << "You have no money. Game over." << std::endl;
            playAgain = false;
        }
    }

    return gameOver();
}

/*********************************************************************
    ** Description: utility function for generating a select menu
    **              returns the index value of the selected option
*********************************************************************/
int Game::menu(std::string options[], int size)
{
    int selectedOption;
    // print a numbered list with each option
    std::cout << "Please select an option: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
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

/*********************************************************************
    ** Description: basic start menu
*********************************************************************/
int Game::startMenu()
{
    const int START_MENU_SIZE = 2;
    std::string startMenuOptions[START_MENU_SIZE] = {
        "Start Game",
        "Quit"
    };
    return menu(startMenuOptions, START_MENU_SIZE);
}

/*********************************************************************
    ** Description: menu that asks if user wants to keep playing
*********************************************************************/
bool Game::playAgain()
{
    std::cout << "Keep playing?" << std::endl;
    std::string yesOrNo[2] = {"Yes", "No"};
    return menu(yesOrNo, 2) == 0;
}

/*********************************************************************
    ** Description: Generates a random event for the day, then 
    **              updates the daily bank value according to the 
    **              day's payoffs and random events
*********************************************************************/
void Game::playTurn(Zoo &zoo)
{
    std::cout << "DAY " << this->day << std::endl;
    std::cout << "----------------\n" << std::endl;
    zoo.generateRandomEvent();
    zoo.updateBankBalance(zoo.getDailyPayoff());
    zoo.incrementAnimalAges();
    zoo.feedAnimals();

    zoo.printDailyStats();
    buyAnimal(zoo);
    zoo.resetPayoff();
    ++day;
}

/*********************************************************************
    ** Description: Allows the user to select an animal to purchase
*********************************************************************/
void Game::buyAnimal(Zoo &zoo)
{
    std::cout << "Would you like to buy an adult animal?" << std::endl;
    std::string yesOrNo[2] = {"Yes", "No"};
    int shouldBuyAnimal = menu(yesOrNo, 2) == 0;

    if (shouldBuyAnimal)
    {
        std::cout << "Which animal would you like to buy?" << std::endl;
        std::string animalOptions[3] = {"Tiger", "Penguin", "Turtle"};
        int selectedAnimalOption = menu(animalOptions, 3);
        switch(selectedAnimalOption)
        {
            case 0:
                zoo.addAnimal(TIGER, 3, true);
                break;
            case 1:
                zoo.addAnimal(PENGUIN, 3, true);
                break;
            case 2:
                zoo.addAnimal(TURTLE, 3, true);
                break;
            default:
                break;
        }
    }
}

/*********************************************************************
    ** Description: basic print statement for game over
*********************************************************************/
void Game::gameOver()
{
    std::cout << "Game Over" << std::endl;
}
