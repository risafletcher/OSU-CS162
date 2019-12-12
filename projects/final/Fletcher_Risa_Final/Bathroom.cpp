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
    name = "Bathroom";
    keyItem = SERVER_CLOTHES;
}

Bathroom::Bathroom(Space *top, Space *right, Space *bottom, Space *left) : 
Space(top, right, bottom, left)
{
    name = "Bathroom";
    keyItem = SERVER_CLOTHES;
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
        dropPlayerItem(player, TOILET_SNAKE);
        player->setHasWon(true);
    }
    else
    {
        cout << "\nYou have no way of plunging the toilet." << endl;
    }
}

void Bathroom::showMenu(Player *player)
{
    cout << "\nBATHROOM" << endl;
    cout << "--------" << endl;
    string options[6] = {
        "Plunge toilet",
        "Check Hamper",
        "Check trash",
        "Drop item here",
        "Pick up dropped item",
        "Keep moving"};
    bool shouldContinue = true;
    while(shouldContinue)
    {
        int menuChoice = menu(options, 6);

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
                selectDropItem(player);
                break;
            case 4:
                selectDroppedItemToPickup(player);
                break;
            default:
                return;
        }

        if (!player->getHasWon())
        {
            cout << "\nContinue searching?" << endl;
            string continueOptions[2] = {"Yes", "No"};
            shouldContinue = menu(continueOptions, 2) == 0;
        }
    }
}
