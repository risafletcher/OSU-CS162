/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  A container for the losers stack
*******************************************************************************/
#include "Losers.hpp"
#include "Character.hpp"
#include <iostream>
#include <memory>

Losers::Losers(int capacity)
{
    stackArray = new std::shared_ptr<Character>[capacity];
    this->capacity = capacity;
    top = 0;
}

void Losers::push(std::shared_ptr<Character> character)
{
    if (top == capacity) throw Losers::Overflow();
    stackArray[top] = character;
    top++;
}

void Losers::pop(std::shared_ptr<Character> character)
{
    if (isEmpty()) throw Losers::Underflow();
    top--;
    character = stackArray[top];
}

bool Losers::isEmpty() const
{
    return top == 0;
}

void Losers::printLosers()
{
    std::cout << "Number of losers: " << actualQuantity << std::endl;
    std::cout << "LOSERS: ";
    for (int i = 0; i < actualQuantity; ++i)
        std::cout << stackArray[i]->getName() << " ";
}

void Losers::addQuantity(int number)
{
    actualQuantity += number;
}