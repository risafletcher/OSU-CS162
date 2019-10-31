/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/29/19
** Description:  Specification file for a Penguin Animal class, which derives
**               from the Animal class
*******************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal
{
    private:
        int foodCost;

    public:
        Penguin();
        Penguin(int);
};

#endif