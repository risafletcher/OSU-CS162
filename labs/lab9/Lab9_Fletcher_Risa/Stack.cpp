/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/1/19
** Description:  A stack class using STL containers
*******************************************************************************/
#include "Stack.hpp"
#include <string>
#include <iostream>

void Stack::menu()
{
    std::cout << "\nSTACK" << std::endl;
    std::cout << "Please enter a string to print as a palindrome: ";
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, string);

    for (int i = 0; i < string.length(); ++i)
        palindrome.push(string.at(i));
}

void Stack::printPalindrome()
{
    while (!palindrome.empty())
    {
        string.push_back(palindrome.top());
        palindrome.pop();
    }
    std::cout << "Your palindrome is: " << string << std::endl;
}
