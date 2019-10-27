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
            std::cout << "Please enter a valid choice. ";
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
        players[i].reset();
        std::cout << "PLAYER " << i + 1 << std::endl;

        std::cout << "Would you like to use a loaded die? (y/n): ";
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

        std::cout << "How many sides should your die have? ";
        players[i].setNumberOfSides(getValidInt());
    }

    for (int i = 0; i < NUMBER_OF_PLAYERS; ++i)
    {
        int hasLoadedDie = players[i].getLoadedDieStatus() == 1;
        if (hasLoadedDie)
            std::cout << "PLAYER " << i + 1 << "'s die is loaded." << std::endl;
        std::cout << "PLAYER " << i + 1 << "'s die has ";
        std::cout << players[i].getNumberOfSides() << " sides." << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
}

void Game::playGame()
{
    std::cout << "Welcome to the dice-rolling war game!" << std::endl;
    // show start menu
    startMenu();
    while (shouldPlay)
    {
        openMenu();

        for (int i = 0; i < numRounds; i++)
        {
            std::cout << "ROUND " << i + 1 << "\n" << std::endl;

            for (int j = 0; j < NUMBER_OF_PLAYERS; j++)
            {
                bool playerHasLoadedDie = players[j].getLoadedDieStatus();
                int numberOfSides = players[j].getNumberOfSides();
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
                std::cout << "PLAYER " << j + 1 << ": " << roll << std::endl;
                players[j].updateRoll(roll);
            }
            int player1Roll = players[0].getRoll();
            int player2Roll = players[1].getRoll();
            std::cout << std::endl;
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

            std::cout << std::endl;
            int player1TotalScore = players[0].getTotalScore();
            int player2TotalScore = players[1].getTotalScore();
            std::cout << "Player 1 total score: " << player1TotalScore << std::endl;
            std::cout << "Player 2 total score: " << player2TotalScore << std::endl;
            std::cout << "----------------------------------" << std::endl;
        }
        int player1TotalScore = players[0].getTotalScore();
        int player2TotalScore = players[1].getTotalScore();

        if (player1TotalScore > player2TotalScore)
            std::cout << "Player 1 wins!" << std::endl;
        if (player1TotalScore < player2TotalScore)
            std::cout << "Player 2 wins!" << std::endl;
        if (player1TotalScore == player2TotalScore)
            std::cout << "Tie!" << std::endl;

        std::cout << '\n' << std::endl;
        std::cout << "Would you like to play another game?" << std::endl;
        startMenu();
    }
}