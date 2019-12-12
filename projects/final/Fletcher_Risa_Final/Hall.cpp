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
    name = "Hall";
    keyItem = SALAD;
}

Hall::Hall(Space *top, Space *right, Space *bottom, Space *left) :
Space(top, right, bottom, left)
{
    name = "Hall";
    keyItem = SALAD;
}

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
            pickUpItem(player, SALAD);
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

void Hall::showMenu(Player *player)
{
    cout << "\nCENTRAL HALL" << endl;
    cout << "------------" << endl;
    string options[6] = {
        "Dust Vase",
        "Talk to Servers",
        "Check beneath tables",
        "Drop item here",
        "Pick up a dropped item",
        "Keep moving"};

    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 6);

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
                selectDropItem(player);
                break;
            case 4:
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
