/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  A class for the board in the program. It accepts coordinates
**               to update but also prints and returns the current board state.
*******************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
    private:
        int rows, columns;
        const char WHITE = ' ';
        const char ANT = '*';
        const char HORIZONTAL_BORDER = '-';
        const char VERTICAL_BORDER = '|';
        char** board;

    public:
        Board(int numRows, int numCols, int startingRow, int startingCol);
    /*********************************************************************
        ** Description: VIEW & GETTER
    *********************************************************************/
        void printBoard();
        char** getBoard();

    /*********************************************************************
        ** Description: ACTION
    *********************************************************************/
        void updateBoard(int row, int col, char value);
        void deleteBoard();
};

#endif