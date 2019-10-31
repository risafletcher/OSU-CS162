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

using std::cin;
using std::cout;
using std::endl;
using std::string;

Game::Game()
{
    this->day = 1;
}

void Game::validateInput()
{

}

void Game::start(Zoo zoo)
{
    int choice = startMenu();
    if (choice == 1)
        gameOver();

    cout << "Before we begin, please purchase 3 animals." << endl;
    cout << "Please select an animal to purchase:" << endl;
    string buyAnimalOptions[3] = {
        "Tiger",
        "Penguin",
        "Turtle"};
    for (int i = 0; i < 3; ++i)
    {
        int selectedOption;
        // loop until input is of valid int type
        while (true)
        {
            // since we're indexing at 1, we need to check for that
            if (std::cin >> selectedOption &&
                selectedOption < 4 &&
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

        if (selectedOption == 1)
            zoo.addAnimal(TIGER, 1, true);
        if (selectedOption == 2)
            zoo.addAnimal(PENGUIN, 1, true);
        if (selectedOption == 3)
            zoo.addAnimal(TURTLE, 1, true);
    }


    // EXTRA CREDIT: Different feed types


    playTurn(zoo);
}

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

int Game::startMenu()
{
    const int START_MENU_SIZE = 2;
    string startMenuOptions[START_MENU_SIZE] = {
        "Start Game",
        "Quit"
    };
    return menu(startMenuOptions, START_MENU_SIZE);
}

void Game::playTurn(Zoo zoo)
{
    

    zoo.resetPayoff();
    ++day;
}

void Game::gameOver()
{

}
