/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for a Node class to be used in a linked list
**               program.
*******************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    public:
        Node();
        Node(int value, Node *prev = nullptr, Node *next = nullptr);
        int val;
        Node *next, *prev;
};

#endif