/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Die class that accepts a number of sides for a die and 
**               provides a method that returns an int higher than a regular
**               Die object.
*******************************************************************************/
#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP
#include "Die.hpp"

class LoadedDie : public Die
{
    public:
        LoadedDie(int);
        int roll();
};

#endif