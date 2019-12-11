/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Hall.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Hall::Hall() : Space()  // call default constructor on base class
{
    name = HALL;
    *items = {SALAD};
    numberOfItems = 1;
}

Hall::Hall(Space *top, Space *right, Space *bottom, Space *left) :
Space(top, right, bottom, left)
{}

void Hall::dustVase()
{
    cout << "\nYou dusted all the vases in the hallway and didn't find ";
    cout << "anything." << endl;
}

void Hall::talkToServers(Player *player)
{
    Item *playerItems = player->getItems();
    int playerNumItems = player->getNumberOfItems();
    bool hasClothes = false;
    for (int i = 0; i < playerNumItems; ++i)
    {
        if (playerItems[i] == SERVER_CLOTHES)
        {
            hasClothes = true;
            cout << "\nA waitstaff asks you to deliver a salad to Melania. ";
            cout << "Salad acquired." << endl;
            player->addItem(SALAD);
            removeItem(SALAD);
        }
    }
    if (!hasClothes)
    {
        cout << "\nA waitstaff tells you to they can only speak to other ";
        cout << "waiters." << endl;
    }
}

void Hall::checkBeneathTables()
{
    cout << "\nYou checked beneath all the tables and found nothing." << endl;
}

void Hall::pickUpItem(Player *player, Item item)
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

void Hall::showMenu(Player *player)
{
    cout << "\nCENTRAL HALL" << endl;
    cout << "------------" << endl;
    string options[4] = {
        "Dust Vase",
        "Talk to Servers",
        "Check beneath tables",
        "Keep moving"};

    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 4);

        switch (menuChoice)
        {
            case 0:
                dustVase();
                break;
            case 1:
                talkToServers(player);
                break;
            case 2:
                checkBeneathTables();
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
