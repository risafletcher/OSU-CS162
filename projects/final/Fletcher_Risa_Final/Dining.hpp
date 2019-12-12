/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef DINING_HPP
#define DINING_HPP
#include "Space.hpp"
#include "Player.hpp"

class Dining : public Space
{
    public:
        Dining();
        Dining(Space *, Space *, Space *, Space *);
        void checkDiningChairs();
        void serveMelania(Player *);
        virtual void showMenu(Player *);
};

#endif