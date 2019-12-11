/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A derived room class
*******************************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "Space.hpp"
#include "Player.hpp"

class Library : public Space
{
    public:
        Library();
        Library(Space *, Space *, Space *, Space *);
        void talkToLibrarian();
        void polishAndSearchDesk(Player *);
        virtual void pickUpItem(Player *, Item);
        virtual void showMenu(Player *);
};

#endif