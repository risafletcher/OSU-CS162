/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#include "Menu.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"
#include <string>
#include <limits>
#include <iostream>
#include <fstream>

void Menu::mainMenu(LinkedList *list)
{
    std::cout << "\nChoose from the following options:\n"
              << std::endl;

    std::string options[9] = {
        "Add a new node to the head",
        "Add a new node to the tail",
        "Delete from head",
        "Delete from tail",
        "Traverse the list recursively",
        "EXTRA CREDIT: Print the value of the Node the head is pointing to",
        "EXTRA CREDIT: Print the value of the Node the tail is pointing to",
        "EXTRA CREDIT: Read numbers from a local file, NumberList.txt",
        "Exit"
    };
    int choice;
    while (choice != 9)
    {
        choice = getMenuOption(options, 9);
        runFunctions(choice, list);
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

void Menu::runFunctions(int choice, LinkedList *list)
{
    if (choice == 1 || choice == 2)
    {
        std::cout << "Enter a value to add to the list: ";
        int value = getValidInt();
        std::cout << std::endl;
        if (choice == 1)
            list->addToHead(value);
        if (choice == 2)
            list->addToTail(value);
        list->traverse();
    }
    if (choice == 3 || choice == 4)
    {
        Node *listHead = list->getHead();
        if (listHead == nullptr)
            std::cout << "Sorry, your list is empty.\n" << std::endl;
        else
        {
            if (choice == 3)
                list->deleteFromHead();
            if (choice == 4)
                list->deleteFromTail();
        }
        list->traverse();
    }
    if (choice == 5)
    {
        Node *listHead = list->getHead();
        if (listHead == nullptr)
            std::cout << "Sorry, your list is empty.\n" << std::endl;
        else
            list->traverseReverse();
    }

    // EXTRA CREDIT: TASK 1: Add two more options:
    // Print the value of the Node the head is pointing to
    // Print the value of the Node the tail is pointing to

        if (choice == 6)
    {
        Node *listHead = list->getHead();
        std::cout << "The value of the head node is " << listHead->val << std::endl;
    }

    if (choice == 7)
    {
        Node *listTail = list->getTail();
        std::cout << "The value of the tail node is " << listTail->val << std::endl;
    }

    // EXTRA CREDIT: Read numbers from list.
    if (choice == 8)
    {
        std::ifstream numberList("NumberList.txt");
        if (!numberList)
            std::cout << "Error reading from file" << std::endl;
        else
        {
            int number;
            while (numberList >> number)
                list->addToTail(number);
            list->traverse();
        }
    }

    else return;
}