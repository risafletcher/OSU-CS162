/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  A class for the ant in the program. Contains ant's location,
**               orientation, and a method to move the ant.
*******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"

enum Orientation { NORTH, EAST, SOUTH, WEST };

class Ant
{
    private:
        int location[2];    // {x, y} coordinates
        Orientation orientation;
        int numSteps;
        const char WHITE = ' ';
        const char BLACK = '#';
        const char ANT = '*';
        const char VERTICAL_BORDER = '|';
        const char HORIZONTAL_BORDER = '-';
        char currentColor;

    public:
        Ant();
        /*********************************************************************
        ** Description: custom constructor to initialize ant's location
        *********************************************************************/
        Ant(int startingRow, int startingCol, int numSteps);

        /*********************************************************************
        ** Description: ACTION
        *********************************************************************/
        void move(Board board);
};

#endif