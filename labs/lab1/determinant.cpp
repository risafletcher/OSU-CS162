#include "determinant.hpp"
#include <iostream>

int Determinant::determinant(int *array[], int size)
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

        int matrixA[size - 1][size -1],
            matrixB[size - 1][size -1],
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

        int aTimesDeterminant = a * (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
        int bTimesDeterminant = b * (matrixB[0][0] * matrixB[1][1]) - (matrixB[0][1] * matrixB[1][0]);
        int cTimesDeterminant = c * (matrixC[0][0] * matrixC[1][1]) - (matrixC[0][1] * matrixC[1][0]);

        return (aTimesDeterminant - bTimesDeterminant) + cTimesDeterminant;
    }
}