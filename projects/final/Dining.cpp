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
    name = DINING;
}

Dining::Dining(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{}

void Dining::checkDiningChairs()
{
    cout << "\nYou checked all of the chairs and found nothing." << endl;
}

void Dining::serveMelania(Player *player)
{
    if (player->hasItem(SALAD))
    {
        player->removeItem(SALAD);
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
    string options[3] = {
        "Check dining chairs",
        "Serve Melania",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 3);

        switch (menuChoice)
        {
        case 0:
            checkDiningChairs();
            break;
        case 1:
            serveMelania(player);
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

void Dining::pickUpItem(Player *player, Item item)
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