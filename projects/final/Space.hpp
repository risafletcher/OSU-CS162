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
    protected:
        Location name;
        Space   *top,
                *right,
                *bottom,
                *left;
        Item *items;
        int numberOfItems;

    public:
        Space();
        Space(Space *top, Space *right, Space *bottom, Space *left);
        ~Space();
        Item *getItems();
        void removeItem(Item);
        void setItem(Item *);
        Space *getTop();
        Space *getRight();
        Space *getBottom();
        Space *getLeft();
        Location getName();
        virtual void pickUpItem(Player *, Item) = 0;
        virtual void showMenu(Player *) = 0;
};

#endif