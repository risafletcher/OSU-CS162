/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Game class that implements the dice-rolling war game.
*******************************************************************************/
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Player.hpp"
#include "getValidInt.hpp"
#include <iostream>
#include <memory>
#include <limits>

void Game::startMenu()
{
    int menuChoice;
    std::cout << "Welcome to the dice-rolling war game!" << std::endl;
    std::cout << "1. Play Game" << std::endl;
    std::cout << "2. Exit Game" << std::endl;
    while (true)
    {
        if (std::cin >> menuChoice && (menuChoice == 1 || menuChoice == 2))
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid choice." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    shouldPlay = menuChoice == 1;
}

void Game::openMenu()
{
    std::cout << "How many rounds would you like to play? ";
    numRounds = getValidInt();

    for (int i = 0; i < NUMBER_OF_PLAYERS; ++i)
    {
        std::cout << "PLAYER " << i + 1 << std::endl;

        std::cout << "Would you like to use a loaded die? (y/N): ";
        char useLoaded;
        while (true)
        {
            if (std::cin >> useLoaded && 
            (std::tolower(useLoaded) == 'y' || std::tolower(useLoaded) == 'n'))
            {
                break;
            }
            else
            {
                std::cout << "Please enter a valid choice." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        players[i].setLoadedDieStatus(std::tolower(useLoaded) == 'y');

        std::cout << "How many sides should your die have?";
        players[i].setNumberOfSides(getValidInt());
    }

    for (int i = 0; i < NUMBER_OF_PLAYERS; ++i)
    {
        std::cout << "PLAYER " << i + 1 << "'s die is loaded: ";
        std::cout << players[i].getLoadedDieStatus() << std::endl;
        std::cout << "PLAYER " << i + 1 << "'s die has ";
        std::cout << players[i].getNumberOfSides() << " sides." << std::endl;
    }
}

void Game::playGame()
{
    // show start menu
    startMenu();
    if (shouldPlay)
    {
        openMenu();

        for (int i = 0; i < numRounds; ++i)
        {
            for (int j = 0; j < NUMBER_OF_PLAYERS; ++j)
            {
                bool playerHasLoadedDie = players[i].getLoadedDieStatus();
                int numberOfSides = players[i].getNumberOfSides();
                int roll;
                if (playerHasLoadedDie)
                {
                    std::shared_ptr<LoadedDie> die = std::make_shared<LoadedDie>(numberOfSides);
                    roll = die->roll();
                }
                else
                {
                    std::shared_ptr<Die> die = std::make_shared<Die>(numberOfSides);
                    roll = die->roll();
                }
                // TODO: this is printing 1 player twice instead of each player once
                std::cout << "PLAYER " << i + 1 << ": " << roll << std::endl;
                players[i].updateRoll(roll);
            }
            int player1Roll = players[0].getRoll();
            int player2Roll = players[1].getRoll();

            if (player1Roll == player2Roll)
                std::cout << "TIE" << std::endl;
            if (player1Roll > player2Roll)
            {
                std::cout << "Player 1 wins this round." << std::endl;
                players[0].updateTotalScore(1);
            }
            if (player1Roll < player2Roll)
            {
                std::cout << "Player 2 wins this round." << std::endl;
                players[1].updateTotalScore(1);
            }
        }
        int player1TotalScore = players[0].getTotalScore();
        int player2TotalScore = players[1].getTotalScore();

        if (player1TotalScore > player2TotalScore)
            std::cout << "Player 1 wins!" << std::endl;
        else
            std::cout << "Player 2 wins!" << std::endl;

        startMenu();
    }
}