#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int matrixSize;
    ReadMatrix readObject;
    Determinant determinantObject;
    // get user input
    cout << "Please choose the size of your matrix:" << endl;
    cout << "Enter \"2\" for a 2x2 or \"3\" for a 3x3: ";
    cin >> matrixSize;
    while (matrixSize != 2 && matrixSize != 3)
    {
        cout << "Please enter 2 or 3: ";
        cin >> matrixSize;
    }

    // pointer to an array of pointers
    int** matrix = new int*[matrixSize];
    // loop through the array of pointers and dynamically allocate memory
    // for the new arrays
    for (int i = 0; i < matrixSize; i++)
        matrix[i] = new int[matrixSize];

    // pass the matrix by pointer
    readObject.readMatrix(matrix, matrixSize);

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
    int calculatedDeterminant = determinantObject.determinant(matrix, matrixSize);
    cout << "The determinant of your matrix is: " << calculatedDeterminant << endl;

    // CLEAN UP
    delete[] matrix;
    matrix = nullptr;
    
    return 0;
}