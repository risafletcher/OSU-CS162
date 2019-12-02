/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/1/19
** Description:  A queue class using STL containers
*******************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <queue>

class Queue
{
    private:
        std::queue<int> queue;
        int numRounds,
            chanceAddToEnd,
            chanceAddToFront;

    public:
        void menu();
        int generateRandomNumber(int);
        void appendNumber(int);
        void removeNumber();
        void play();
        void print();
};

#endif
