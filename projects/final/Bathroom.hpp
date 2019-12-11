/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef BATHROOM_HPP
#define BATHROOM_HPP
#include "Space.hpp"
#include "Player.hpp"

class Bathroom : public Space
{
    public:
        Bathroom();
        Bathroom(Space *, Space *, Space *, Space *);
        virtual void pickUpItem(Player *, Item);
        void plungeToilet(Player *);
        void checkHamper(Player *);
        void checkTrash();
        virtual void showMenu(Player *);
};

#endif