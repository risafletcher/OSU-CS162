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
    *items = {KEY};
    numberOfItems = 1;
}

Library::Library(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
}

void Library::talkToLibrarian()
{
    cout << "He doesn't seem interested in talking to you." << endl;
}

void Library::polishAndSearchDesk(Player *player)
{
    cout << "You've found a key!" << endl;
    pickUpItem(player, KEY);
}

void Library::pickUpItem(Player *player, Item item)
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

void Library::showMenu(Player *player)
{
    cout << "\nLIBRARY" << endl;
    cout << "-------" << endl;
    string options[3] = {
        "Talk to Librarian",
        "Polish and Search Desk",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 3);

        switch (menuChoice)
        {
        case 0:
            talkToLibrarian();
            break;
        case 1:
            polishAndSearchDesk(player);
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
