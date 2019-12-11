/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef STAIRWELL_HPP
#define STAIRWELL_HPP
#include "Space.hpp"
#include "Player.hpp"

class Stairwell : public Space
{
    public:
        Stairwell();
        Stairwell(Space *, Space *, Space *, Space *);
        void walkUpstairs();
        void checkCabinet(Player *);
        virtual void pickUpItem(Player *, Item);
        virtual void showMenu(Player *);
};

#endif