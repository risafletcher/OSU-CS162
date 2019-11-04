/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/03/19
** Description:  A series of recursive functions: 1. Print a string in reverse,
**               2. Calculate the sum of an array of ints, 3. Calcuate the 
**               triangular number of an int N
*******************************************************************************/
#ifndef RECURSIVE_METHODS_HPP
#define RECURSIVE_METHODS_HPP
#include <string>

/*********************************************************************
    ** Description: prints reversed string
*********************************************************************/
void printReversedString(std::string);

/*********************************************************************
    ** Description: calculates the sum of an array of ints
*********************************************************************/
int calculateSum(int*, int);

/*********************************************************************
    ** Description: calculates the triangular number of an integer
*********************************************************************/
int calculateTriangularNumber(int);

#endif