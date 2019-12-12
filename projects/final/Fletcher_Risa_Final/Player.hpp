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
    string itemNames[6] = {
    "Toilet Snake",
    "Server's clothes",
    "Key",
    "Salad",
    "Note",
    "Wig"};

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
        void incrementNumberOfItems();
        void decrementNumberOfItems();
        void printInventory();
        void setHasWon(bool);
        bool getHasWon();
};

#endif