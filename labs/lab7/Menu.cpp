/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/17/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#include "Menu.hpp"
#include "Queue.hpp"
#include <string>
#include <limits>
#include <iostream>

void Menu::mainMenu(Queue *queue)
{
    std::cout << "\nChoose from the following options:\n"
              << std::endl;

    std::string options[5] = {
        "Add a value to the back of the queue",
        "Display the front value",
        "Remove the front node",
        "Display the queue's content",
        "Exit"};
    int choice;
    while (choice != 5)
    {
        choice = getMenuOption(options, 5);
        runFunctions(choice, queue);
        std::cout << std::endl;
    }
}

/*********************************************************************
    ** Description: takes in an array of strings (menu options) and 
    **              returns the index of the selected option
*********************************************************************/
int Menu::getMenuOption(std::string options[], int size)
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

/*********************************************************************
    ** Description: gets a valid integer from input stream
*********************************************************************/
int Menu::getValidInt()
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

/*********************************************************************
    ** Description: runs the queue functions according to choice
*********************************************************************/
void Menu::runFunctions(int choice, Queue *queue)
{
    if (choice == 1)
    {
        std::cout << "Enter a value to add to the queue: ";
        int value = getValidInt();
        std::cout << std::endl;
        queue->addBack(value);
    }

    if (choice == 2)
        std::cout << "The front value is: " << queue->getFront() << std::endl;

    if (choice == 3)
        queue->removeFront();

    if (choice == 4)
        queue->printQueue();

    else
        return;
}