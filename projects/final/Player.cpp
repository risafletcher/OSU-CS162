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
    items = 0;
}

Player::~Player()
{
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

void Player::addItem(Item item)
{
    numberOfItems++;
    Item *newItems = new Item[numberOfItems];
    for (int i = 0; i < numberOfItems - 1; ++i)
        newItems[i] = items[i];
    newItems[numberOfItems] = item;
}

void Player::removeItem(Item item)
{
    bool foundMatch = false;
    for (int i; i < numberOfItems; ++i)
    {
        if (items[i] == item)
        {
            foundMatch = true;
        }
        if (foundMatch)
        {
            items[i] = items[i + 1];
            numberOfItems--;
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