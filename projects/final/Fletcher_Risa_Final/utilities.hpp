/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  Utility functions for the game
*******************************************************************************/
#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <string>

using std::string;

enum Location
{
    BATHROOM,
    STAIRWELL,
    LIBRARY,
    HALL,
    RECEPTION,
    DINING
};

enum Item
{
    TOILET_SNAKE,
    SERVER_CLOTHES,
    KEY,
    SALAD,
    NOTE,
    WIG,
    NONE
};

int menu(string[], int);
int menuWithLabels(string[], string[], int);

#endif