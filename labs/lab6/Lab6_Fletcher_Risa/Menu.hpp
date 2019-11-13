/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "LinkedList.hpp"

class Menu
{
    private:
        int choice;
        int getMenuOption(std::string options[], int);

    public:
        int getValidInt();
        void runFunctions(int, LinkedList*);
        void mainMenu(LinkedList*);
};

#endif