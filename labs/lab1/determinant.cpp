#include "determinant.hpp"
#include <iostream>

int determinant(int **array, int size)
{

    if (size == 2)
    {
        return (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
    }

    if (size == 3)
    {
        int a = array[0][0];
        int b = array[0][1];
        int c = array[0][2];

        int matrixA[size - 1][size - 1],
            matrixB[size - 1][size - 1],
            matrixC[size - 1][size - 1];

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j == 0)
                {
                    matrixB[i - 1][j] = array[i][j];
                    matrixC[i - 1][j] = array[i][j];
                }
                if (j == 1)
                {
                    matrixA[i - 1][j - 1] = array[i][j];
                    matrixC[i - 1][j] = array[i][j];
                }
                if (j == 2)
                {
                    matrixA[i - 1][j - 1] = array[i][j];
                    matrixB[i - 1][j - 1] = array[i][j];
                }
            }
        }

        int aTimesDeterminant = a * determinant(matrixA, 2);
        int bTimesDeterminant = b * determinant(matrixB, 2);
        int cTimesDeterminant = c * determinant(matrixC, 2);

        return aTimesDeterminant - bTimesDeterminant - cTimesDeterminant;
    }
}