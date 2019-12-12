/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/10/19
** Description:  A Clue-like game to find the president's missing wig
*******************************************************************************/
#include <iostream>
#include <string>
#include "utilities.hpp"
#include "Game.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Find the President's Missing Wig" << endl;
    cout << "----------------------------------" << endl;
    cout << "The president's wig has gone missing somewhere in the ";
    cout << "White House. We need your help to find it!" << endl;

    string playOrExit[] = {"Play", "Exit"};
    int playOrExitChoice = menu(playOrExit, 2);

    if (playOrExitChoice == 0)
    {
        Game game;
        game.play();
    }

    return 0;
}