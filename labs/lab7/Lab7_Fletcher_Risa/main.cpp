/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/17/19
** Description:  A program that performs operations on a queue
*******************************************************************************/
#include "Queue.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to my queue!" << std::endl;

    Queue queue;
    Menu menu;
    menu.mainMenu(&queue);

    return 0;
}