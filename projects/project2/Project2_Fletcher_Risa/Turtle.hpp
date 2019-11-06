/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for a Turtle Animal class, which derives
**               from the Animal class
*******************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal
{
    public:
        Turtle();
        Turtle(int);
};

#endif