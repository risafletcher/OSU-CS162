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
    player = new Player();
    bathroom = new Bathroom();
    dining = new Dining();
    hall = new Hall();
    library = new Library();
    reception = new Reception();
    stairwell = new Stairwell();

    bathroom->setArea(nullptr, hall, library, nullptr);
    dining->setArea(stairwell, nullptr, nullptr, reception);
    hall->setArea(nullptr, stairwell, reception, bathroom);
    library->setArea(bathroom, reception, nullptr, nullptr);
    reception->setArea(hall, dining, nullptr, library);
    stairwell->setArea(nullptr, nullptr, dining, hall);
    currentLocation = reception;
}

Game::~Game()
{
    delete player;
    player = nullptr;
    delete bathroom;
    bathroom = nullptr;
    delete dining;
    dining = nullptr;
    delete hall;
    hall = nullptr;
    delete library;
    library = nullptr;
    delete reception;
    reception = nullptr;
    delete stairwell;
    stairwell = nullptr;
}

string Game::getLabel(Space *space)
{
    if (space != nullptr)
        return space->getName();
    return "WALL";
}

void Game::play()
{
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
    steps = 1;

    bool playerHasWon = player->getHasWon();
    while (!playerHasWon && steps < 20)
    {
        cout << "\nSTEPS REMAINING: " << 20 - steps << endl;
        cout << "\nCURRENT INVENTORY" << endl;
        cout << "-----------------" << endl;
        player->printInventory();
        if (player->getNumberOfItems() >= 4)
        {
            cout << "--------------------------------------------------";
            cout << "-------" << endl;
            cout << "\nWARNING: Your inventory is full. You should drop ";
            cout << "something." << endl;
            cout << "--------------------------------------------------";
            cout << "-------" << endl;
        }
        cout << "\nWhere should you go next?" << endl;
        Space *top = currentLocation->getTop();
        Space *right = currentLocation->getRight();
        Space *bottom = currentLocation->getBottom();
        Space *left = currentLocation->getLeft();

        string labels[5] = {
            getLabel(top),
            getLabel(right),
            getLabel(bottom),
            getLabel(left),
            "Quit Game"};

        int locationChoice = menuWithLabels(directions, labels, 5);
        if (locationChoice == 4)
            return;

        bool playerCanMove = canMove(locationChoice);
        while (!playerCanMove)
        {
            cout << "\nYou can't move that way. Try again." << endl;
            locationChoice = menuWithLabels(directions, labels, 5);
            playerCanMove = canMove(locationChoice);
        }

        if (locationChoice == 0)
            currentLocation = top;
        if (locationChoice == 1)
            currentLocation = right;
        if (locationChoice == 2)
            currentLocation = bottom;
        if (locationChoice == 3)
            currentLocation = left;

        playerHasWon = player->getHasWon();
        currentLocation->showMenu(player);
        steps++;
    }

    if (playerHasWon)
        cout << "You win!";

    if (steps >= 20)
        cout << "You've run out of steps. Game over." << endl;
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
