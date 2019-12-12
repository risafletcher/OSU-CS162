/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  An abstract class for each room
*******************************************************************************/
#include "Space.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Space::Space()
{
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    items = nullptr;
    listOfItemNames = nullptr;
    numberOfItems = 0;
}

Space::Space(Space *top, Space *right, Space *bottom, Space *left)
{
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
    items = nullptr;
    listOfItemNames = nullptr;
    numberOfItems = 0;
}

Space::~Space()
{
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    delete[] items;
    items = nullptr;
}

Space *Space::getTop()
{
    return top;
}

Space *Space::getRight()
{
    return right;
}

Space *Space::getBottom()
{
    return bottom;
}

Space *Space::getLeft()
{
    return left;
}

string Space::getName()
{
    return name;
}

void Space::removeItem(Item item)
{
    bool foundMatch = false;
    for (int i = 0; i < numberOfItems; ++i)
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

void Space::setArea(Space *top, Space *right, Space *bottom, Space *left)
{
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
}

void Space::selectDropItem(Player *player)
{
    int playersNumberOfItems = player->getNumberOfItems();
    if (playersNumberOfItems == 0)
        cout << "\nYou have nothing to drop." << endl;
    else
    {
        Item *playerInventory = player->getItems();
        int playerNumberOfItems = player->getNumberOfItems();
        cout << "\nWhich item would you like to drop?"
             << endl;
        string *playerItemNames = new string[playerNumberOfItems + 1];
        for (int i = 0; i < playersNumberOfItems; ++i)
        {
            int nameIndex = playerInventory[i];
            playerItemNames[i] = itemNames[nameIndex];
        }
        playerItemNames[playerNumberOfItems] = "Nevermind";
        int itemIndexChoice = menu(playerItemNames, playerNumberOfItems + 1);
        if (itemIndexChoice == playerNumberOfItems) // if they chose to exit
            return;
        Item selectedItem = playerInventory[itemIndexChoice];
        dropPlayerItem(player, selectedItem);
        delete[] playerItemNames;
        playerItemNames = nullptr;
    }
}

void Space::getListOfItemNames()
{
    string *newListOfItemNames = new string[numberOfItems + 1];
    for (int i = 0; i < numberOfItems; ++i)
    {
        int nameIndex = items[i];
        newListOfItemNames[i] = itemNames[nameIndex];
    }
    newListOfItemNames[numberOfItems] = "Nevermind";
    if (listOfItemNames != nullptr)
    {
        delete[] listOfItemNames;
        listOfItemNames = nullptr;
    }
    listOfItemNames = newListOfItemNames;
    newListOfItemNames = nullptr;
}

void Space::dropPlayerItem(Player *player, Item item)
{
    Item *updatedItems = new Item[numberOfItems + 1];
    for (int i = 0; i < numberOfItems; ++i)
        updatedItems[i] = items[i];
    updatedItems[numberOfItems] = item;
    numberOfItems++;
    player->removeItem(item);
    if (numberOfItems > 0)
    {
        delete[] items;
        items = nullptr;
    }
    items = updatedItems;
    updatedItems = nullptr;
}

void Space::pickUpItem(Player *player, Item item)
{
    if (player->hasItem(item))
        cout << "You already have this item." << endl;
    else if (item == keyItem)
    {
        player->addItem(item);
        if (numberOfItems > 0)
            numberOfItems--;
    }
    else
    {    
        bool foundMatch = false;
        for (int i = 0; i < numberOfItems; ++i)
        {
            if (items[i] == item)   // make sure the item is available
            {
                player->addItem(item);
                foundMatch = true;
            }
            if (foundMatch)
            {
                items[i] = items[i + 1];
                numberOfItems--;
            }
        }
    }
}

void Space::selectDroppedItemToPickup(Player *player)
{
    if (numberOfItems == 0)
        cout << "\nThere are no items here to pick up." << endl;
    else
    {    
        cout << "\nWhich item would you like to pick up?" << endl;
        getListOfItemNames();
        int selectedItemIndex = menu(listOfItemNames, numberOfItems + 1);
        for (int i = 0; i < numberOfItems; ++i)
        if (selectedItemIndex != numberOfItems)
            pickUpItem(player, items[selectedItemIndex]);
    }
}