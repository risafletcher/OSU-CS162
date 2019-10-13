/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  A class for the board in the program. It accepts coordinates
**               to update but also prints and returns the current board state.
*******************************************************************************/
#include "board.hpp"
#include <iostream>

/*********************************************************************
    ** Description: CONSTRUCTOR
*********************************************************************/
Board::Board(int numRows, int numCols, int startingRow, int startingCol)
{
    rows = numRows;
    columns = numCols;
    // *board == board[0]
    // board = {*board}
    // assigning contents of board the address (pointer) to a new array of
    // ints with length num rows
    board = new char *[numRows + 2];    // board = address to a new { 1, 2, 3, etc }
    // loop through the contents of new array and assign it the value of 
    // a new array with length numCols
    // board = address to { {1, 2, 3}, {1, 2, 3}, {1, 2, 3} }
    for (int i = 0; i < numCols + 2; i++)
    {
        board[i] = new char[numCols + 2];
    }
    // create board with borders and starting ant in middle
    for (int i = 0; i < numRows + 2; i++)
    {
        for (int j = 0; j < numCols + 2; j++)
        {
            if (i == startingRow && j == startingCol)
                board[i][j] = ANT;
            else if (i == 0 || i == numRows + 1)
                board[i][j] = HORIZONTAL_BORDER;
            else if ((j == 0 || j == numCols + 1) && i != 0 && i != (numRows + 1))
                board[i][j] = VERTICAL_BORDER;
            else
                board[i][j] = WHITE;
        }
    }
}

/*********************************************************************
    ** Description: GETTERS
*********************************************************************/

void Board::printBoard()
{
    for (int i = 0; i < rows + 2; i++)
    {
        for (int j = 0; j < columns + 2; j++)
            std::cout << board[i][j] << ' ';
        std::cout << std::endl;
    }
}

char** Board::getBoard()
{
    return board;
}

/*********************************************************************
    ** Description: ACTIONS
*********************************************************************/

void Board::updateBoard(int rowCoord, int colCoord, char value)
{
    board[rowCoord][colCoord] = value;
}

void Board::deleteBoard()
{
    delete[] board;
    board = nullptr;
}