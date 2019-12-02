/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/17/19
** Description:  A Queue class that provides various methods for adding values
**               to a queue, removing them, and accessing them
*******************************************************************************/
#include "Queue.hpp"
#include <iostream>
#include <limits>

/*********************************************************************
    ** CONSTRUCTORS
*********************************************************************/
Queue::Queue()
{
    head = nullptr;
}

Queue::Queue(int val, QueueNode *prev, QueueNode *next)
{
    head = new QueueNode(val, prev, next);
}

/*********************************************************************
    ** DESTRUCTOR
*********************************************************************/

Queue::~Queue()
{
    QueueNode *garbage = head;
    while (garbage != nullptr)
    {
        head = head->next;
        garbage->next = nullptr;
        garbage->prev = nullptr;
        delete garbage;
        garbage = head;
    }
}

/*********************************************************************
    ** Description: checks if queue is empty
*********************************************************************/
bool Queue::isEmpty()
{
    return head == nullptr;
 }

/*********************************************************************
    ** Description: adds a node with a new value to the end of the 
    **              queue
*********************************************************************/
 void Queue::addBack(int value)
 {
     if (isEmpty())
         head = new QueueNode(value);
     else
     {
         QueueNode *last = head;
         while (last->next != head && last->next != nullptr)
             last = last->next;
         last->next = new QueueNode(value, last, head);
         head->prev = last->next;
     }
}

/*********************************************************************
    ** Description: gets the value of the front node in the queue
*********************************************************************/
int Queue::getFront()
{
    return head->val;
}

/*********************************************************************
    ** Description: deletes the front node in the queue and
    **              reassigns it to the next node
*********************************************************************/
void Queue::removeFront()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
    }
    else
    {
        if (head->next == nullptr)  // if there's only one node in the queue, remove it
        {
            delete head;
            head = nullptr;
        }
        else
        {
            QueueNode *temp = head; 
            QueueNode *rear = head;   
            while(rear->next != head && rear->next != nullptr)   // loop through to find the last item in the queue
                rear = rear->next;
            head = head->next;          // shift the head down one, since we're removing it
            if (head == rear)           // if only one node remains, set its prev and next to null
            {
                head->prev = nullptr;
                head->next = nullptr;
            }
            else                        // else, set the new head's prev to the rear
            {                           // and the rear's next to the new head
                head->prev = rear;
                rear->next = head;
            }
            delete temp;                // delete the original head node
        }
    }
}

/*********************************************************************
    ** Description: loops through the nodes and prints their values
*********************************************************************/
void Queue::printQueue()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
    }
    else
    {
        QueueNode *temp = head;
        std::cout << "Your queue: ";
        while (temp->next != head && temp->next != nullptr)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << temp->val << std::endl;
    }
}