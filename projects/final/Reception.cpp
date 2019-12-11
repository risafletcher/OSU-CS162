/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Reception.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Reception::Reception() : Space()
{
    name = RECEPTION;
    *items = {NOTE};
    numberOfItems = 1;
}

Reception::Reception(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
}

void Reception::checkDesks()
{
    cout << "You checked the library desks and found nothing." << endl;
}

void Reception::checkBeneathRug()
{
    cout << "You checked beneath the rug and found nothing." << endl;
}

void Reception::checkCoatPockets(Player *player)
{
    cout << "You found a very controversial note from Putin. Perhaps Melania ";
    cout << "would like to see this!" << endl;
    pickUpItem(player, NOTE);
}

void Reception::pickUpItem(Player *player, Item item)
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

void Reception::showMenu(Player *player)
{
    cout << "\nRECEPTION ROOM" << endl;
    cout << "--------------" << endl;
    string options[4] = {
        "Check desks",
        "Check coat pockets",
        "Check beneath rug",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 4);

        switch (menuChoice)
        {
        case 0:
            checkDesks();
            break;
        case 1:
            checkCoatPockets(player);
            break;
        case 2:
            checkBeneathRug();
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
