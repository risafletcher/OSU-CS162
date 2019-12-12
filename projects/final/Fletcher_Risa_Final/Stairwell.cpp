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
    name = "Stairwell";
    keyItem = TOILET_SNAKE;
}

Stairwell::Stairwell(Space *top, Space *right, Space *bottom, Space *left) :
Space(top, right, bottom, left)
{
    name = "Stairwell";
    keyItem = TOILET_SNAKE;
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
        cout << "\nIt appears to be cleaning supplies. You acquired the toilet ";
        cout << "snake." << endl;
        player->removeItem(KEY);
        pickUpItem(player, TOILET_SNAKE);
    }
    else
    {
        cout << "\nIt looks like you'll need a key.\n" << endl;
    }
}

void Stairwell::showMenu(Player *player)
{
    cout << "\nSTAIRWELL" << endl;
    cout << "--------" << endl;
    string options[5] = {
        "Walk upstairs",
        "Check cabinet",
        "Drop item here",
        "Pick up a dropped item",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 5);

        switch (menuChoice)
        {
        case 0:
            walkUpstairs();
            break;
        case 1:
            checkCabinet(player);
            break;
        case 2:
            selectDropItem(player);
            break;
        case 3:
            selectDroppedItemToPickup(player);
            break;
        default:
            return;
        }

        cout << "\nContinue searching?" << endl;
        string continueOptions[2] = {"Yes", "No"};
        shouldContinue = menu(continueOptions, 2) == 0;
    }
}
