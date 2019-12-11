/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Stairwell.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Stairwell::Stairwell() : Space()
{
    name = STAIRWELL;
    *items = {TOILET_SNAKE};
    numberOfItems = 1;
}

Stairwell::Stairwell(Space *top, Space *right, Space *bottom, Space *left) :
Space(top, right, bottom, left)
{
}

void Stairwell::walkUpstairs()
{
    cout << "You are stopped by security. Upstairs is strictly off-limits.";
    cout << endl;
}

void Stairwell::checkCabinet(Player *player)
{
    if (player->hasItem(KEY))
    {
        cout << "It appears to be cleaning supplies. You acquired the toilet ";
        cout << "snake." << endl;
        player->removeItem(KEY);
        pickUpItem(player, TOILET_SNAKE);
    }
}

void Stairwell::pickUpItem(Player *player, Item item)
{
    bool foundMatch = false;
    for (int i; i < numberOfItems; ++i)
    {
        if (items[i] == item)
        {
            player->addItem(items[i]);
            foundMatch = true;
        }
        if (foundMatch)
        {
            items[i] = items[i + 1];
            numberOfItems--;
        }
    }
}

void Stairwell::showMenu(Player *player)
{
    cout << "\nSTAIRWELL" << endl;
    cout << "--------" << endl;
    string options[3] = {
        "Walk upstairs",
        "Check cabinet",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 3);

        switch (menuChoice)
        {
        case 0:
            walkUpstairs();
            break;
        case 1:
            checkCabinet(player);
            break;
        case 2:
            return;
        default:
            break;
        }

        cout << "\nContinue searching?" << endl;
        string continueOptions[2] = {"Yes", "No"};
        shouldContinue = menu(continueOptions, 2) == 0;
    }
}
