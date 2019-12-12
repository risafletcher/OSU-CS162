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
    name = "Reception";
    keyItem = NOTE;
}

Reception::Reception(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
    name = "Reception";
    keyItem = NOTE;
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

void Reception::showMenu(Player *player)
{
    cout << "\nRECEPTION ROOM" << endl;
    cout << "--------------" << endl;
    string options[6] = {
        "Check desks",
        "Check coat pockets",
        "Check beneath rug",
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
            checkDesks();
            break;
        case 1:
            checkCoatPockets(player);
            break;
        case 2:
            checkBeneathRug();
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
