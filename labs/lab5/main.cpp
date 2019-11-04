/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/03/19
** Description:  A series of recursive functions: 1. Print a string in reverse,
**               2. Calculate the sum of an array of ints, 3. Calcuate the 
**               triangular number of an int N
*******************************************************************************/
#include "menu.hpp"
#include <iostream>
#include <string>

int main()
{
    // present the menu and collect the user's choice
    int selectedOption = getFunctionChoice();
    // depending on their selected option, run the appropriate method
    while (selectedOption != 4)
    {
        switch (selectedOption)
        {
            case 1:
                runReverseString();
                break;
            case 2:
                runCalculateSum();
                break;
            case 3:
                runCalculateTriangular();
                break;
            default:
                break;
        }
        // present menu again 
        selectedOption = getFunctionChoice();
    }

    return 0;
}