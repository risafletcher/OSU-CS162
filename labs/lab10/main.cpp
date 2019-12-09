/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/8/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#include "record.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;

int main()
{
    cout << "This program will measure and compare the running time of a recursive and\n";
    cout << "iterative implementation of the Fibonacci calculation.\n";
    cout << "Results are measured in nanoseconds(ns).\n";

    int menuChoice = mainMenu();
    switch (menuChoice)
    {
        case 1:
            getUserInput();
            break;
        case 2:
            test();
            break;
        default:
            break;
    }
    return 0;
}
