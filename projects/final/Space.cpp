/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  An abstract class for each room
*******************************************************************************/
#include "Space.hpp"
#include <iostream>

using std::cout;
using std::endl;

Space::Space()
{
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    items = nullptr;
    numberOfItems = 0;
}

Space::Space(Space *top, Space *right, Space *bottom, Space *left)
{
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
    numberOfItems = 0;
}

Space::~Space()
{
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
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

Location Space::getName()
{
    return name;
}

void Space::removeItem(Item item)
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