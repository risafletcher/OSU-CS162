/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A class for the game itself
*******************************************************************************/
#include "Game.hpp"
#include "utilities.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

Game::Game()
{
    steps = 0;
    bathroom = new Bathroom(nullptr, hall, library, nullptr);
    dining = new Dining(stairwell, nullptr, nullptr, reception);
    hall = new Hall(nullptr, stairwell, reception, bathroom);
    library = new Library(bathroom, reception, nullptr, nullptr);
    reception = new Reception(hall, dining, nullptr, library);
    stairwell = new Stairwell(nullptr, nullptr, dining, hall);
}

Game::~Game()
{
    bathroom = nullptr;
    dining = nullptr;
    hall = nullptr;
    library = nullptr;
    reception = nullptr;
    stairwell = nullptr;
}

void Game::play()
{
    Player *player = new Player();
    currentLocation = reception;
    cout << "\nYou're a maid in the White House and the president has ";
    cout << "accused you of theft. You must find his wig by the end of ";
    cout << "day or you will be deported." << endl;

    cout << "\nYou will have a total of 20 steps before the end of the day. ";
    cout << "Use them wisely." << endl;
    cout << "\nYou will find objects along the way but please know you can ";
    cout << "only carry 4 items at a time." << endl;

    cout << "\nYou begin your search in the Reception Room, or, the ";
    cout << "main entrance" << endl;
    currentLocation->showMenu(player);
    while (!player->getHasWon())
    {
        cout<< "Where should you go next?" << endl;
        int locationChoice = menu(directions, 5);
        if (locationChoice == 4)
            return;
        while (!canMove(locationChoice))
        {
            cout << "\nYou can't move that way. Try again." << endl;
            locationChoice = menu(directions, 5);
        }

        currentLocation = getNewSpace(locationChoice);
        currentLocation->showMenu(player);
    }
}

bool Game::canMove(int direction)
{
    if (direction == 0)
        return currentLocation->getTop() != nullptr;
    if (direction == 1)
        return currentLocation->getRight() != nullptr;
    if (direction == 2)
        return currentLocation->getBottom() != nullptr;
    if (direction == 3)
        return currentLocation->getLeft() != nullptr;
    else
        return false;
}

Space* Game::getNewSpace(int direction)
{
    switch (direction)
    {
        case 0:
            return currentLocation->getTop();
        case 1:
            return currentLocation->getRight();
        case 2:
            return currentLocation->getBottom();
        case 3:
            return currentLocation->getLeft();
        default:
            break;
    }
}
