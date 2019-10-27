/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A class that holds a number of die sides and provides a method
**               for a random "toss" which returns an int between 1 - N
*******************************************************************************/
#include "Die.hpp"
#include <iostream>

Die::Die()
{
    int n = 0;
}

Die::Die(int n)
{
    this->n = n;
}

int Die::randomInt()
{
    return std::rand() % n + 1;
}

int Die::roll()
{
    return randomInt();
}