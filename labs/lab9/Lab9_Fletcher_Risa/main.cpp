/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/1/19
** Description:  Stack and Queues
*******************************************************************************/
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <limits>

int main()
{
    std::cout << "1. Test buffer" << std::endl;
    std::cout << "2. Create palindrome" << std::endl;
    std::cout << "3. Exit" << std::endl;
    int choice;
    while (true)
    {
        if (std::cin >> choice && choice > 0 && choice < 4)
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

    if (choice == 1)
    {
        Queue queue;
        queue.menu();
        queue.play();
    }
    if (choice == 2)
    {
        Stack stack;
        stack.menu();
        stack.printPalindrome();
    }

    return 0;
}