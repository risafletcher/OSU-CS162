/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Implementation for a Node class to be used in a linked list
**               program.
*******************************************************************************/
#include "Node.hpp"

Node::Node()
{
    this->prev = nullptr;
    this->next = nullptr;
}

Node::Node(int val, Node *prev, Node *next)
{
    this->val = val;
    this->prev = prev;
    this->next = next;
}