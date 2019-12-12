/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A class for the player, which tracks their items and position
*******************************************************************************/
#include "Player.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Player::Player()
{
    items = nullptr;
    numberOfItems = 0;
    hasWon = false;
}

Player::~Player()
{
    delete[] items;
    items = nullptr;
}

Item* Player::getItems()
{
    return items;
}

int Player::getNumberOfItems()
{
    return numberOfItems;
}

void Player::incrementNumberOfItems()
{
    numberOfItems++;
}

void Player::decrementNumberOfItems()
{
    numberOfItems--;
}

void Player::addItem(Item item)
{
    if (numberOfItems >= 4)
        cout << "You cannot carry any more items. Drop something." << endl;
    else
    {
        incrementNumberOfItems();
        Item *newItems = new Item[numberOfItems];
        for (int i = 0; i < numberOfItems - 1; ++i)
            newItems[i] = items[i];
        newItems[numberOfItems - 1] = item;
        if (items != nullptr)
        {
            delete[] items;
            items = nullptr;
        }
        items = newItems;

        newItems = nullptr;
    }
}

void Player::removeItem(Item item)
{
    for (int i = 0; i < numberOfItems; ++i)
    {
        if (items[i] == item)
        {
            for (int j = i; j < numberOfItems - 1; ++j)
                items[j] = items[j + 1];
            decrementNumberOfItems();
            break;
        }
    }
}

bool Player::hasItem(Item item)
{
    for (int i = 0; i < numberOfItems; ++i)
    {
        if (items[i] == item)
            return true;
    }
    return false;
}

void Player::setHasWon(bool hasWon)
{
    this->hasWon = hasWon;
}

bool Player::getHasWon()
{
    return hasWon;
}

void Player::printInventory()
{
    if (items != nullptr)
    {
        if (numberOfItems <= 0)
            cout << "No items." << endl;
        else
        {
            for (int i = 0; i < numberOfItems; ++i)
            {
                int nameIndex = items[i];
                cout << itemNames[nameIndex] << endl;
            }
            cout << endl;
        }
    }
}