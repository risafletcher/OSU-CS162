/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/11/19
** Description:  A program for Langton's Ant, an algorithm that prints the
**               movement of an "ant" on a board, according to a set of rules.
*******************************************************************************/

#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "getValidInt.hpp"
#include <iostream>
#include <string>


int main()
{
    // START MENU
    const int START_MENU_SIZE = 2;
    std::string startMenuOptions[START_MENU_SIZE] = {
        "Start Langton's Ant Simulation",
        "Quit"
    };

    std::cout << "WELCOME TO LANGTON'S ANT" << std::endl;
    int startMenuChoice = menu(startMenuOptions, START_MENU_SIZE);
    // exit if they decide to quit
    if (startMenuChoice == 1)
        return 0;

    // in case the user would like to play again, wrap program in while loop
    int endMenuChoice = 0;
    // we are doing a while loop because the user has the option to replay the game
    // at the end
    while (endMenuChoice == 0)
    {
        // COLLECT board specs
        int numRows,
            numCols,
            numSteps,
            startingRow,
            startingCol;
        bool randomStartingPoint;

        std::cout << "Please enter the following information:" << std::endl;

        std::cout << "Number of rows: ";
        numRows = getValidInt();

        std::cout << "Number of columns: ";
        numCols = getValidInt();

        std::cout << "Number of steps: ";
        numSteps = getValidInt();

        std::string yesNoOptions[2] = {"Yes", "No"};

        // EXTRA CREDIT: Offer a random starting point option
        std::cout << "Would you like a random starting location?" << std::endl;
        randomStartingPoint = menu(yesNoOptions, 2) == 0;
        // pick a random number between 1 and the number of rows/cols specified
        if (randomStartingPoint)
        {
            startingRow = std::rand() % numRows + 1;
            startingCol = std::rand() % numCols + 1;
        }
        else
        {
            // notice that we are checking to make sure each input is within range
            std::cout << "Starting row of the ant: ";
            startingRow = getValidInt();

            while (startingRow > numRows || startingRow < 1)
            {
                std::cout << "Pleast enter a number between 1 and " << numRows << ": ";
                startingRow = getValidInt();
            }

            std::cout << "Starting column of the ant: ";
            startingCol = getValidInt();

            while (startingCol > numCols || startingCol < 1)
            {
                std::cout << "Pleast enter a number between 1 and " << numCols << ": ";
                startingCol = getValidInt();
            }
        }
        
        // instantiate our board and ant objects
        Board board(numRows, numCols, startingRow, startingCol);

        Ant ant(startingRow, startingCol, numSteps);

        // print the board's initial step
        board.printBoard();

        // for each step, move the ant
        for (int i = 0; i < numSteps; i++)
        {
            ant.move(board);
        }

        // END MENU
        const int END_MENU_SIZE = 2;
        std::string endMenuOptions[END_MENU_SIZE] = {
            "Play again",
            "Quit"
        };

        // clean up / free dynamically allocated memory
        board.deleteBoard();
        endMenuChoice = menu(endMenuOptions, END_MENU_SIZE);
    }

    return 0;
}