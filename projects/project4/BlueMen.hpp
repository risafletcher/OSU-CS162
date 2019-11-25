/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for derived Character BlueMen
*******************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen : public Character
{
    public:
        BlueMen();
        BlueMen(string);
        virtual void damage(int, int);
};

#endif