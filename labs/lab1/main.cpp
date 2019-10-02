#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int matrixSize;

    cout << "Please choose the size of your matrix:" << endl;
    cout << "Enter "2" for a 2x2 or "3" for a 3x3: ";
    cin >> matrixSize >> endl;
    while (matrixSize != 2 && matrixSize != 3)
    {
        cout << "Please enter 2 or 3: ";
        cin >> matrixSize >> endl;
    }
    return 0;
}