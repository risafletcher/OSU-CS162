/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef HALL_HPP
#define HALL_HPP
#include "Space.hpp"
#include "Player.hpp"

class Hall : public Space
{
    public:
        Hall();
        Hall(Space *, Space *, Space *, Space *);
        void dustVase();
        void talkToServers(Player *);
        void checkBeneathTables();
        virtual void pickUpItem(Player *, Item);
        virtual void showMenu(Player *);
};

#endif