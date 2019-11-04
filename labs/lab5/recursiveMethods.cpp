/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/03/19
** Description:  A series of recursive functions: 1. Print a string in reverse,
**               2. Calculate the sum of an array of ints, 3. Calcuate the 
**               triangular number of an int N
*******************************************************************************/
#include "recursiveMethods.hpp"
#include <iostream>
#include <string>

/*********************************************************************
    ** Description: prints reversed string
*********************************************************************/
void printReversedString(const std::string stringToReverse)
{
    int stringSize = stringToReverse.size();

    if (stringSize == 1)
        std::cout << stringToReverse << "\n" << std::endl;
    else
    {
        std::cout << stringToReverse[stringSize - 1];
        std::string stringWithLastLetterRemoved = stringToReverse.substr(0, stringSize - 1);
        return printReversedString(stringWithLastLetterRemoved);
    }
}
    


/*********************************************************************
    ** Description: calculates the sum of an array of ints
*********************************************************************/
int calculateSum(int *integers, int size)
{
    if (size == 0)
        return integers[0];
    return integers[size] + calculateSum(integers, size - 1);
}

/*********************************************************************
    ** Description: calculates the triangular number of an integer
*********************************************************************/
int calculateTriangularNumber(int n)
{
    if (n == 0)
        return 0;
    return n + calculateTriangularNumber(n - 1);
}