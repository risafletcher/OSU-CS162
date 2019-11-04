/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/03/19
** Description:  A menu to choose between 3 recursive functions
*******************************************************************************/
#include "menu.hpp"
#include "recursiveMethods.hpp"
#include <iostream>
#include <string>
#include <limits>

/*********************************************************************
    ** Description: returns an option number (1-4) depending on ths
    **              user's choice
*********************************************************************/
int getFunctionChoice()
{
    int selectedOption;
    std::cout << "Please select a function:" << std::endl;
    std::cout << "1. Reverse a string\n";
    std::cout << "2. Calculate the sum of an array of numbers\n";
    std::cout << "3. Calculate the triangular number of an integer\n";
    std::cout << "4. Quit" << std::endl;

    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (std::cin >> selectedOption &&
            selectedOption < 5 &&
            selectedOption != 0)
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return selectedOption;
}

/*********************************************************************
    ** Description: utility method for validating int inputs
*********************************************************************/
int getValidInt()
{
    int input;

    while (true)
    {
        if (std::cin >> input)
        {
            break;
        }
        else
        {
            // using a standard library "limits" to ignore any inputs that
            // are non-numeric. This prevents the program from crashing.
            std::cout << "Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

/*********************************************************************
    ** Description: runs the printReversedString method by first
    **              prompting the user for a string to reverse.
*********************************************************************/
void runReverseString()
{
    std::string stringToReverse;
    std::cout << "Please provide a string to reverse: ";
    std::cin.ignore();
    std::getline(std::cin, stringToReverse);

    printReversedString(stringToReverse);
}

/*********************************************************************
    ** Description: runs the calculateSum method by first prompting
    **              the user for an array size and values for each.
*********************************************************************/
void runCalculateSum()
{
    int arraySize;
    int *array;

    std::cout << "How many integers would you like to add up?";
    arraySize = getValidInt();
    // dynamically allocate memory for array
    array = new int[arraySize];

    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << "Enter an integer: ";
        array[i] = getValidInt();
    }

    std::cout << "The sum is " << calculateSum(array, arraySize) << "\n" << std::endl;

    delete[] array;
    array = nullptr;
}

/*********************************************************************
    ** Description: runs the calculateTriangularNumber method by
    **              first accepting an int value below 10,000.
*********************************************************************/
void runCalculateTriangular()
{
    std::cout << "Please enter a number: ";
    int value = getValidInt();
    if (value > 10000)
    {
        std::cout << "Your input is too large. Please try a smaller number:";
        value = getValidInt();
    }
    std::cout << "The triangular number of " << value << " is ";
    std::cout << calculateTriangularNumber(value) << "\n" << std::endl;
}