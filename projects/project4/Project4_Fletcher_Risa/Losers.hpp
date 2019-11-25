/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  A container for the losers stack
*******************************************************************************/
#ifndef LOSERS_HPP
#define LOSERS_HPP
#include "Character.hpp"
#include <memory>
// from book, see p. 1187
class Losers
{
    std::shared_ptr<Character> *stackArray;
    int capacity;
    int actualQuantity = 0;
    int top;

    public:
        Losers(int);
        void push(std::shared_ptr<Character>);
        void pop(std::shared_ptr<Character>);
        bool isEmpty() const;
        void addQuantity(int);
        void printLosers();
        class Overflow {};
        class Underflow {};
};

#endif