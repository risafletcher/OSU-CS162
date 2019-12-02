/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/1/19
** Description:  A queue class using STL containers
*******************************************************************************/
#include "Queue.hpp"
#include <iostream>
#include <queue>
#include <limits>

int getValidInt()
{
    int input;
    while (true)
    {
        if (std::cin >> input && input <= 100)
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

void Queue::menu()
{
    std::cout << "\nQUEUE" << std::endl;
    std::cout << "How many rounds should be simulated? ";
    numRounds = getValidInt();
    std::cout << "Percentage chance to put a randomly generated number at the ";
    std::cout << "end of the buffer: ";
    chanceAddToEnd = getValidInt();
    std::cout << "Percentage chance to take out a randomly generated number at ";
    std::cout << "the front of the buffer: ";
    chanceAddToFront = getValidInt();
}

int Queue::generateRandomNumber(int limit)
{
    return rand() % limit + 1;
}

void Queue::play()
{
    srand(time(NULL));  // set seed value so numbers are consistently random
    for (int i = 0; i < numRounds; ++i)
    {
        int N = generateRandomNumber(1000);
        int rand1 = generateRandomNumber(100);
        int rand2 = generateRandomNumber(100);
        if (rand1 <= chanceAddToEnd)
            appendNumber(N);
        if (rand2 <= chanceAddToFront)
            removeNumber();
        print();
    }
}

void Queue::appendNumber(int number)
{
    queue.push(number);
};

void Queue::removeNumber()
{
    if (!queue.empty())
        queue.pop();
}

void Queue::print()
{
    std::cout << "Buffer: ";
    std::queue<int> queueCopy = queue;
    while (!queueCopy.empty())
    {
        std::cout << queueCopy.front() << " ";
        queueCopy.pop();
    }
    std::cout << std::endl;
    std::cout << "Buffer length: " << queue.size() << std::endl;
    double average;
    if (numRounds > 0)
        average = (average * (numRounds - 1) + queue.size() / numRounds);
    else
        average = queue.size();
    std::cout << "Average buffer length: " << average << std::endl;
}