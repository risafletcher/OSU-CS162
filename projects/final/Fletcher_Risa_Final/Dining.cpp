/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#include "Dining.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Dining::Dining() : Space()
{
    name = "Dining Room";
}

Dining::Dining(Space *top, Space *right, Space *bottom, Space *left)
: Space(top, right, bottom, left)
{
    name = "Dining Room";
}

void Dining::checkDiningChairs()
{
    cout << "\nYou checked all of the chairs and found nothing." << endl;
}

void Dining::serveMelania(Player *player)
{
    if (player->hasItem(SALAD))
    {
        dropPlayerItem(player, SALAD);
        dropPlayerItem(player, NOTE);
        cout << "\nMelania is pleased. You show her the note. She complains ";
        cout << "about the president and admits to flushing the wig down the ";
        cout << "toilet." << endl;
    }
    else
    {
        cout << "You have nothing to serve." << endl;
    }
}

void Dining::showMenu(Player *player)
{
    cout << "\nDINING ROOM" << endl;
    cout << "-----------" << endl;
    string options[5] = {
        "Check dining chairs",
        "Serve Melania",
        "Drop item here",
        "Pick up dropped item",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 5);

        switch (menuChoice)
        {
        case 0:
            checkDiningChairs();
            break;
        case 1:
            serveMelania(player);
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
