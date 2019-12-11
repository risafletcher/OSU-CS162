/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A class for the player, which tracks their items and position
*******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "utilities.hpp"

using std::string;

class Player
{
    private:
        Item *items;
        int numberOfItems;
        bool hasWon;

    public:
        Player();
        ~Player();
        Item *getItems();
        int getNumberOfItems();
        void addItem(Item);
        bool hasItem(Item);
        void removeItem(Item);
        void setHasWon(bool);
        bool getHasWon();
};

#endif