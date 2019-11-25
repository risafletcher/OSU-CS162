/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for derived Character Medusa
*******************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"

class Medusa : public Character
{
    public:
        Medusa();
        Medusa(string);
        virtual int attackPlayer();
};

#endif