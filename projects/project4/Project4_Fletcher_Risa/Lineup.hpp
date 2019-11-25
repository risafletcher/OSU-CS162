/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  A Lineup class which is basically a queue for the characters
**               who are still in the tournament
*******************************************************************************/
#ifndef LINEUP_HPP
#define LINEUP_HPP
#include "Character.hpp"
#include <memory>

using std::shared_ptr;

class Lineup
{
    struct LineupNode
    {
        LineupNode *next;
        LineupNode *prev;
        shared_ptr<Character> character;

        LineupNode(shared_ptr<Character> characterIn,
                   LineupNode *previousCharacter = nullptr,
                   LineupNode *nextCharacter = nullptr)
        {
            character = characterIn;
            prev = previousCharacter;
            next = nextCharacter;
        }
    };

    private:
        LineupNode *head;
        int points = 0;

    public:
        Lineup();
        Lineup( shared_ptr<Character> character,
                LineupNode *prev = nullptr,
                LineupNode *next = nullptr);
        ~Lineup();

        bool isEmpty();
        void addBack(shared_ptr<Character> character);
        shared_ptr<Character> getFront();
        void removeFront();
        void printLineup();
        int getPoints();
        void addPoints(int);
};

#endif