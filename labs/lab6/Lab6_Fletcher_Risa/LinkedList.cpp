/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for a Linked List class, which includes
**               methods for adding, deleting, and traversing the list
*******************************************************************************/
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    Node *nodePtr = head;
    while(nodePtr != nullptr)
    {
        Node *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

void LinkedList::addToHead(int value)
{
    if (head == nullptr)
    {
        head = new Node(value);
        tail = head;
    }
    else
    {
        Node *newNode = new Node(value, nullptr, head);
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::addToTail(int value)
{
    if (head == nullptr)
    {    
        head = new Node(value);
        tail = head;
    }
    else
    {
        Node *newNode = new Node(value, tail);
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::deleteFromHead()
{
    if (!head) return;
    if (head->next == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node *secondNode = head->next;
        secondNode->prev = nullptr;
        head = secondNode;
    }
}

void LinkedList::deleteFromTail()
{
    if (!tail)
        return;
    if (tail->prev == nullptr)
    {
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        Node *secondToLastNode = tail->prev;
        secondToLastNode->next = nullptr;
        delete tail;
        tail = secondToLastNode;
    }
}

void LinkedList::traverse() const
{
    if (head != nullptr)
    {
        Node *nodePtr = head;
        std::cout << "Your linked list is: ";
        while (nodePtr != nullptr)
        {
            std::cout << nodePtr->val << " ";
            nodePtr = nodePtr->next;
        };
        std::cout << "\n"
                  << std::endl;
        delete nodePtr;
        nodePtr = nullptr;
    }
}

void LinkedList::traverseReverse() const
{
    if (tail != nullptr)
    {
        Node *nodePtr = tail;
        std::cout << "Your reversed linked list is: ";
        while (nodePtr != nullptr)
        {
            std::cout << nodePtr->val << " ";
            nodePtr = nodePtr->prev;
        }
        std::cout << std::endl;
        delete nodePtr;
        nodePtr = nullptr;
    }
}

Node* LinkedList::getHead()
{
    return head;
}

Node* LinkedList::getTail()
{
    return tail;
}
