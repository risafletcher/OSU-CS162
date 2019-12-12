/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef RECEPTION_HPP
#define RECEPTION_HPP
#include "Space.hpp"
#include "Player.hpp"

class Reception : public Space
{
    public:
        Reception();
        Reception(Space *, Space *, Space *, Space *);
        void checkDesks();
        void checkCoatPockets(Player *);
        void checkBeneathRug();
        virtual void showMenu(Player *);
};

#endif