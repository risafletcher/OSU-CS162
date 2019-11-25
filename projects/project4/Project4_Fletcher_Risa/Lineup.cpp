/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  A Lineup class which is basically a queue for the characters
**               who are still in the tournament
*******************************************************************************/
#include "Lineup.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>

/*********************************************************************
    ** CONSTRUCTORS
*********************************************************************/
Lineup::Lineup()
{
    head = nullptr;
}

Lineup::Lineup(shared_ptr<Character> character, LineupNode *prev, LineupNode *next)
{
    head = new LineupNode(character, prev, next);
}

/*********************************************************************
    ** DESTRUCTOR
*********************************************************************/

Lineup::~Lineup()
{
    LineupNode *garbage = head;
    while (garbage != nullptr)
    {
        head = head->next;
        garbage->next = nullptr;
        garbage->prev = nullptr;
        delete garbage;
        garbage = head;
    }
    points = 0;
}

/*********************************************************************
    ** Description: checks if queue is empty
*********************************************************************/
bool Lineup::isEmpty()
{
    return head == nullptr;
}

/*********************************************************************
    ** Description: adds a node with a new character to the end of the 
    **              queue
*********************************************************************/
void Lineup::addBack(shared_ptr<Character> character)
{
    if (isEmpty())
        head = new LineupNode(character);
    else
    {
        LineupNode *last = head;
        while (last->next != head && last->next != nullptr)
            last = last->next;
        last->next = new LineupNode(character, last, head);
        head->prev = last->next;
    }
}

/*********************************************************************
    ** Description: gets the character at the front node in the queue
*********************************************************************/
shared_ptr<Character> Lineup::getFront()
{
    return head->character;
}

/*********************************************************************
    ** Description: deletes the front node in the queue and
    **              reassigns it to the next node
*********************************************************************/
void Lineup::removeFront()
{
    if (!isEmpty())
    {
        if (head->next == nullptr) // if there's only one node in the queue, remove it
        {
            delete head;
            head = nullptr;
        }
        else
        {
            LineupNode *temp = head;
            LineupNode *rear = head;
            while (rear->next != head && rear->next != nullptr) // loop through to find the last item in the queue
                rear = rear->next;
            head = head->next; // shift the head down one, since we're removing it
            if (head == rear)  // if only one node remains, set its prev and next to null
            {
                head->prev = nullptr;
                head->next = nullptr;
            }
            else // else, set the new head's prev to the rear
            {    // and the rear's next to the new head
                head->prev = rear;
                rear->next = head;
            }
            delete temp; // delete the original head node
        }
    }
}

/*********************************************************************
    ** Description: loops through the nodes and prints the characters
*********************************************************************/
void Lineup::printLineup()
{
    if (isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
    }
    else
    {
        LineupNode *temp = head;
        std::cout << "Your queue: ";
        while (temp->next != head && temp->next != nullptr)
        {
            std::cout << temp->character->getName() << " ";
            temp = temp->next;
        }
        std::cout << temp->character->getName() << std::endl;
    }
}

int Lineup::getPoints()
{
    return points;
}

void Lineup::addPoints(int numPoints)
{
    points += numPoints;
}
