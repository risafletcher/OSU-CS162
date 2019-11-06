/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for a Tiger Animal class, which derives
**               from the Animal class
*******************************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal
{
    public:
        Tiger();
        Tiger(int);
};

#endif