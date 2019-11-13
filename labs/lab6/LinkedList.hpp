/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for a Linked List class, which includes
**               methods for adding, deleting, and traversing the list
*******************************************************************************/
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "Node.hpp"

class LinkedList
{
    protected:
        Node *head, *tail;
    
    public:
        LinkedList();
        ~LinkedList();
        void addToHead(int);
        void addToTail(int);
        void deleteFromHead();
        void deleteFromTail();
        void traverse() const;
        void traverseReverse() const;
        Node* getHead();
        Node* getTail();
};

#endif