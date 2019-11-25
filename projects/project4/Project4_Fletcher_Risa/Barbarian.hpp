/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for derived Character Barbarian
*******************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

class Barbarian : public Character
{
    public:
        Barbarian();
        Barbarian(string);
};

#endif