/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Bathroom.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Bathroom::Bathroom() : Space()
{
    name = BATHROOM;
    *items = {SERVER_CLOTHES};
    numberOfItems = 1;
}

Bathroom::Bathroom(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
}

void Bathroom::checkTrash()
{
    cout << "\nYou rifled through the trash and found nothing." << endl;
}

void Bathroom::checkHamper(Player *player)
{
    cout << "You've found some dirty server's clothes and put them on.";
    cout << endl;
    pickUpItem(player, SERVER_CLOTHES);
}

void Bathroom::plungeToilet(Player *player)
{
    if (player->hasItem(TOILET_SNAKE))
    {
        cout << "\nCongratulations! Your found the wig!" << endl;
        player->setHasWon(true);
    }
    else
    {
        cout << "\nYou have no way of plunging the toilet." << endl;
    }
}

void Bathroom::pickUpItem(Player *player, Item item)
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

void Bathroom::showMenu(Player *player)
{
    cout << "\nBATHROOM" << endl;
    cout << "--------" << endl;
    string options[4] = {
        "Plunge toilet",
        "Check Hamper",
        "Check trash",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 4);

        switch (menuChoice)
        {
            case 0:
                plungeToilet(player);
                break;
            case 1:
                checkHamper(player);
                break;
            case 2:
                checkTrash();
                break;
            case 3:
                return;
            default:
                break;
        }

        cout << "\nContinue searching?" << endl;
        string continueOptions[2] = {"Yes", "No"};
        shouldContinue = menu(continueOptions, 2) == 0;
    }
}
