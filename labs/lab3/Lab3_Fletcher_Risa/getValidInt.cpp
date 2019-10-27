#include "getValidInt.hpp"
#include <string>
#include <iostream>
#include <limits>

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
            std::cout << "Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return input;
}