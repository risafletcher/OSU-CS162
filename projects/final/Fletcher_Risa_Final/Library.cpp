/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Library.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Library::Library() : Space()
{
    name = "Library";
    keyItem = KEY;
}

Library::Library(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
    name = "Library";
    keyItem = KEY;
}

void Library::talkToLibrarian()
{
    cout << "\nHe doesn't seem interested in talking to you." << endl;
}

void Library::polishAndSearchDesk(Player *player)
{
    cout << "\nYou've found a key!" << endl;
    pickUpItem(player, KEY);
}

void Library::showMenu(Player *player)
{
    cout << "\nLIBRARY" << endl;
    cout << "-------" << endl;
    string options[5] = {
        "Talk to Librarian",
        "Polish and Search Desk",
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
            talkToLibrarian();
            break;
        case 1:
            polishAndSearchDesk(player);
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
