/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for derived Character HarryPotter
*******************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"

class HarryPotter : public Character
{
    private:
        bool hasBeenRevived;

    public:
        HarryPotter();
        HarryPotter(string);
        virtual void damage(int, int);
};

#endif