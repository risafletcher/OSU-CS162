/*********************************************************************
    ** Description: utility function for generating a select menu
    **              returns the index value of the selected option
*********************************************************************/
#include <string>
#include <iostream>
#include <limits>


int menu(std::string options[], int size)
{
    int selectedOption;
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
            std::cout << "Please enter a valid option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return selectedOption - 1;
}
