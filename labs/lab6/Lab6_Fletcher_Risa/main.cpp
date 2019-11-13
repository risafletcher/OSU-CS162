/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  A program that accepts user input to perform a series of
**               linked list operations.
*******************************************************************************/
#include "LinkedList.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to my linked list!" << std::endl;

    LinkedList list;
    Menu menu;
    menu.mainMenu(&list);

    return 0;
}