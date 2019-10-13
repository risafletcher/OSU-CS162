/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  Implementation of a menu function that accepts an array of
**               string prompts and returns the index of the selected option.
*******************************************************************************/
#include "menu.hpp"
#include <string>
#include <iostream>
#include <limits>

int menu(std::string options[], int size)
{
    int selectedOption;
    // print a numbered list with each option
    std::cout << "Please select an option: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
    // loop until input is of valid int type
    while(true)
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
            std::cout << "Please enter a valid option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return selectedOption- 1;
}