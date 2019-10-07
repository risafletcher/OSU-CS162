/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/06/19
** Description:  Implementation of a read matrix function. Accepts a pointer to
**               a 2D array (empty) and a size int. Accepts user inputs and 
**               populates the matrix.
*******************************************************************************/
#include "readMatrix.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readMatrix(int *array[], int size)
{
    // determine the number of elements in the matrix
    int numberOfElements = size * size;
    // prompt
    cout << "Please enter " << numberOfElements << " numbers." << endl;
    // loop through the 2D array and populate with user input data
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> array[i][j];
        }
    }
}