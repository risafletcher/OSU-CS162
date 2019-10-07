/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/06/19
** Description:  A program that reads and prints a 2x2 or 3x3 matrix and its
**               determinant.
*******************************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int matrixSize;

    // get user input
    cout << "Please choose the size of your matrix." << endl;
    cout << "Enter \"2\" for a 2x2 or \"3\" for a 3x3: " << endl;
    cin >> matrixSize;
    while (matrixSize != 2 && matrixSize != 3)
    {
        cin.clear();
        cout << "Please enter 2 or 3: " << endl;
        cin >> matrixSize;
    }

    // pointer to an array of pointers
    int** matrix = new int*[matrixSize];
    // loop through the array of pointers and dynamically allocate memory
    // for the new arrays

    for (int i = 0; i < matrixSize; i++)
        matrix[i] = new int[matrixSize];

    // pass the address (pointer) of the array of arrays
    // to the read function
    readMatrix(matrix, matrixSize);

    // print the matrix
    cout << "Your matrix: " << endl;
    for (int j = 0; j < matrixSize; j++)
    {
        for (int k = 0; k < matrixSize; k++)
        {
            cout << matrix[j][k] << " ";
        }
        cout << endl;
    }

    // print the determinant
    int calculatedDeterminant = determinant(matrix, matrixSize);
    cout << "The determinant of your matrix is: " << calculatedDeterminant << endl;

    // CLEAN UP
    delete[] matrix;
    matrix = nullptr;
    return 0;
}