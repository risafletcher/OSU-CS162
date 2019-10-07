/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/06/19
** Description:  Implementation of a determinant function. Accepts a pointer to
**               a 2D array (an int matrix) as well as a size int.
*******************************************************************************/
#include "determinant.hpp"

int determinant(int *array[], int size)
{
    if (size == 2)
    {
        return (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
    }

    if (size == 3)
    {
        // following mathisfun.com's 3x3 matrix determinant formula
        int a = array[0][0];
        int b = array[0][1];
        int c = array[0][2];

        // a, b, and c's matrices should be the resulting matrix when
        // all values in the row and column of the variable are removed
        const int SIZE = 2;
        int aMatrix[SIZE][SIZE]; // define three 2D arrays to store new matrices
        int bMatrix[SIZE][SIZE];
        int cMatrix[SIZE][SIZE];


        // iterate upon the existing array but offset the row by 1
        for (int arrayRow = 1; arrayRow < SIZE + 1; arrayRow++)
        {
            for (int arrayCol = 0; arrayCol < SIZE + 1; arrayCol++)
            {
                // if the iteratee is in a, b, or c's column, don't include it
                // in the new matrices for a,b, and c
                if (arrayCol != 0)
                    aMatrix[arrayRow - 1][arrayCol - 1] = array[arrayRow][arrayCol];
                if (arrayCol != 1)
                {
                    if (arrayCol == 2)
                        bMatrix[arrayRow - 1][arrayCol - 1] = array[arrayRow][arrayCol];
                    if (arrayCol == 0)    
                        bMatrix[arrayRow - 1][arrayCol] = array[arrayRow][arrayCol];
                }
                if (arrayCol != 2)
                    cMatrix[arrayRow - 1][arrayCol] = array[arrayRow][arrayCol];
            }
        }

        // get determinants for each of the new matrices
        int determinantA = (aMatrix[0][0] * aMatrix[1][1]) - (aMatrix[0][1] * aMatrix[1][0]);
        int determinantB = (bMatrix[0][0] * bMatrix[1][1]) - (bMatrix[0][1] * bMatrix[1][0]);
        int determinantC = (cMatrix[0][0] * cMatrix[1][1]) - (cMatrix[0][1] * cMatrix[1][0]);

        return (a * determinantA) - (b * determinantB) + (c * determinantC);
    }
}