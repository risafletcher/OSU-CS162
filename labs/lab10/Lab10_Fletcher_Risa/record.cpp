/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/8/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#include "record.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <chrono>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

int getValidInt()
{
    int input;
    while (true)
    {
        if (std::cin >> input && input <= 50)
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid integer (0 - 50)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

int getMenuOption(std::string options[], int size)
{
    int selectedOption;
    // print a numbered list with each option
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (std::cin >> selectedOption &&
            selectedOption < size + 1 &&
            selectedOption != 0)
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid choice." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return selectedOption;
}

int mainMenu()
{
    std::cout << "\nChoose from the following options:\n"
              << std::endl;

    std::string options[3] = {
        "Enter a number",
        "Test (10, 25, 50)",
        "Exit"};
    return getMenuOption(options, 3);
}

void printRow(int N, unsigned long int val, unsigned long int nonRecursive, unsigned long int recursive)
{
    cout << "| " << setw(4) << left << N;
    cout << " | " << setw(20) << left << val;
    cout << " | " << setw(20) << left << nonRecursive;
    cout << " | " << setw(20) << left << recursive << endl;
}

void getUserInput()
{
    cout << "Please enter an input number: ";
    int input = getValidInt();
    cout << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "| " << setw(4) << left << "N";
    cout << " | " << setw(20) << left << "Fib #"; 
    cout << " | " << setw(20) << left << "Non-Recursive(ns)";
    cout << " | " << setw(20) << left << "Recursive(ns)" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    auto startNR = high_resolution_clock::now();
    unsigned long int value = fibonacciNonRecursive(input);
    auto endNR = high_resolution_clock::now();
    auto NrDuration = duration_cast<nanoseconds>(endNR - startNR);

    auto startR = high_resolution_clock::now();
    fibonacciRecursive(input);
    auto endR = high_resolution_clock::now();
    auto RDuration = duration_cast<nanoseconds>(endR - startR);

    printRow(input, value, NrDuration.count(), RDuration.count());
}

void test()
{
    int testValues[3] = {10, 25, 50};
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "| " << setw(4) << left << "N";
    cout << " | " << setw(20) << left << "Fib #"; 
    cout << " | " << setw(20) << left << "Non-Recursive(ns)";
    cout << " | " << setw(20) << left << "Recursive(ns)" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 3; ++i)
    {
        int input = testValues[i];

        auto startNR = high_resolution_clock::now();
        unsigned long int value = fibonacciNonRecursive(input);
        auto endNR = high_resolution_clock::now();
        auto NrDuration = duration_cast<nanoseconds>(endNR - startNR);

        auto startR = high_resolution_clock::now();
        fibonacciRecursive(input);
        auto endR = high_resolution_clock::now();
        auto RDuration = duration_cast<nanoseconds>(endR - startR);

        printRow(input, value, NrDuration.count(), RDuration.count());
    }
}

int fibonacciNonRecursive(const int &n)
{
    int first = 0;
    int second = 1;
    int counter = 2;
    while (counter < n)
    {
        int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }
    if (n == 0) return 0;
    else return first + second;
}

int fibonacciRecursive(const int &n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
