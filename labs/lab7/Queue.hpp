/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/17/19
** Description:  A Queue class that provides various methods for adding values
**               to a queue, removing them, and accessing them
*******************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
    struct QueueNode
    {
        QueueNode *next;
        QueueNode *prev;
        int val;

        QueueNode(int value, QueueNode *previousNode = nullptr, QueueNode *nextNode = nullptr)
        {
            val = value;
            prev = previousNode;
            next = nextNode;
        }
    };
    
    QueueNode *head;
    
    public:
        Queue();
        Queue(int val, QueueNode *prev = nullptr, QueueNode *next = nullptr);
        ~Queue();

        bool isEmpty();
        void addBack(int val);
        int getFront();
        void removeFront();
        void printQueue();
};

#endif
