/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for derived Character Vampire
*******************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
#include <string>

using std::string;

class Vampire : public Character
{
    public:
        Vampire();
        Vampire(string);
        bool charm();
        virtual void damage(int, int);
};

#endif