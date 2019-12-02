/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/1/19
** Description:  A stack class using STL containers
*******************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <string>
#include <stack>

class Stack
{
    private:
        std::string string;
        std::stack<char> palindrome;

    public:
        void menu();
        void printPalindrome();
};

#endif