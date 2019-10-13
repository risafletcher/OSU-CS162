/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  A class for the ant in the program. Contains ant's location,
**               orientation, and a method to move the ant.
*******************************************************************************/
#include "ant.hpp"
#include "board.hpp"

/*********************************************************************
    ** Description: CONSTRUCTOR
*********************************************************************/
Ant::Ant(int startingRow, int startingCol, int steps)
{
    location[0] = startingRow;
    location[1] = startingCol;
    numSteps = steps;
    currentColor = WHITE;
    orientation = NORTH;
}


/*********************************************************************
    ** Description: ACTION
*********************************************************************/
void Ant::move(Board board)
{
    int currentRow = location[0];
    int currentCol = location[1];
    int newRow = currentRow;
    int newCol = currentCol;

    char **currentBoard = board.getBoard();

    bool topIsBorder = currentBoard[currentRow - 1][currentCol] == HORIZONTAL_BORDER;
    bool leftIsBorder = currentBoard[currentRow][currentCol - 1] == VERTICAL_BORDER;
    bool bottomIsBorder = currentBoard[currentRow + 1][currentCol] == HORIZONTAL_BORDER;
    bool rightIsBorder = currentBoard[currentRow][currentCol + 1] == VERTICAL_BORDER;

    // 1. Check ant's orientation
    // 2. Check the current tile's color
    // 3. Depending on the ant's orientation, check if destination tile is a border
    //      a. If it is, proceed another 90 degrees and recheck
    //      b. If it isn't, move the ant
    switch (orientation)
    {
        case NORTH:
            if (currentColor == WHITE)
            {
                if (rightIsBorder)
                {
                    orientation = SOUTH;
                    return move(board);
                }
                else
                {
                    orientation = EAST;
                    currentColor = BLACK;
                    newCol++;
                    break;
                }
            }
            if (currentColor == BLACK)
            {
                if (leftIsBorder)
                {
                    orientation = SOUTH;
                    return move(board);
                }
                else
                {
                    orientation = WEST;
                    currentColor = WHITE;
                    newCol--;
                    break;
                }
            }
        case EAST:
            if (currentColor == WHITE)
            {
                if (bottomIsBorder)
                {
                    orientation = WEST;
                    return move(board);
                }
                else
                {
                    orientation = SOUTH;
                    currentColor = BLACK;
                    newRow++;
                    break;
                }
            }
            if (currentColor == BLACK)
            {
                if (topIsBorder)
                {
                    orientation = WEST;
                    return move(board);
                }
                else
                {
                    orientation = NORTH;
                    currentColor = WHITE;
                    newRow--;
                    break;
                }
            }
        case SOUTH:
            if (currentColor == WHITE)
            {
                if (leftIsBorder)
                {
                    orientation = NORTH;
                    return move(board);
                }
                else
                {
                    orientation = WEST;
                    currentColor = BLACK;
                    newCol--;
                    break;
                }
            }
            if (currentColor == BLACK)
            {
                if (rightIsBorder)
                {
                    orientation = NORTH;
                    return move(board);
                }
                else
                {
                    orientation = EAST;
                    currentColor = WHITE;
                    newCol++;
                    break;
                }
            }
        case WEST:
            if (currentColor == WHITE)
            {
                if (topIsBorder)
                {
                    orientation = EAST;
                    return move(board);
                }
                else
                {
                    orientation = NORTH;
                    currentColor = BLACK;
                    newRow--;
                    break;
                }
            }
            if (currentColor == BLACK)
            {
                if (bottomIsBorder)
                {
                    orientation = EAST;
                    return move(board);
                }
                else
                {
                    orientation = SOUTH;
                    currentColor = WHITE;
                    newRow++;
                    break;
                }
            }
        default:
            break;
    }
    // update board so old tile has updated color
    board.updateBoard(currentRow, currentCol, currentColor);

    // update current color
    currentColor = currentBoard[newRow][newCol];

    // move ant to the new location
    board.updateBoard(newRow, newCol, ANT);

    // update location
    location[0] = newRow;
    location[1] = newCol;
    board.printBoard();
}