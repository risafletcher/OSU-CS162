/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  An abstract class for each room
*******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include "utilities.hpp"
#include "Player.hpp"
#include <string>

using std::string;

class Space
{
    string itemNames[6] = {
    "Toilet Snake",
    "Server's clothes",
    "Key",
    "Salad",
    "Note",
    "Wig"};

    protected:
        string name;
        string *listOfItemNames;
        Space *top;
        Space *right;
        Space *bottom;
        Space *left;
        Item *items;
        Item keyItem;
        int numberOfItems;

    public:
        Space();
        Space(Space *top, Space *right, Space *bottom, Space *left);
        ~Space();
        Item getItem(Item);
        void removeItem(Item);
        void setItem(Item *);
        void dropPlayerItem(Player *, Item);
        void selectDropItem(Player *);
        void selectDroppedItemToPickup(Player *);
        void setArea(Space *top, Space *right, Space *bottom, Space *left);
        Space *getTop();
        Space *getRight();
        Space *getBottom();
        Space *getLeft();
        string getName();
        void getListOfItemNames();
        void pickUpItem(Player *, Item);
        virtual void showMenu(Player *) = 0;
};

#endif