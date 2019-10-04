#include "readMatrix.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void ReadMatrix::readMatrix(int *array[], int size)
{
    int numberOfElements;

    if (size == 2)
        numberOfElements = 4;
    if (size == 3)
        numberOfElements = 9;

    cout << "Please enter " << numberOfElements << " numbers." << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> array[i][j];
        }
    }
}