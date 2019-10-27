/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Player class which contains information on die preference
**               and sides preference.
*******************************************************************************/
#include "Player.hpp"

void Player::setLoadedDieStatus(bool isLoaded)
{
    hasLoadedDie = isLoaded;
};

bool Player::getLoadedDieStatus()
{
    return hasLoadedDie;
}

void Player::setNumberOfSides(int numberOfSides)
{
    this->numberOfSides = numberOfSides;
};

int Player::getNumberOfSides()
{
    return numberOfSides;
}

void Player::updateRoll(int roll)
{
    this->roll = roll;
}

void Player::updateTotalScore(int score)
{
    totalScore += score;
};

void Player::reset()
{
    totalScore = 0;
}

int Player::getRoll()
{
    return roll;
}

int Player::getTotalScore()
{
    return totalScore;
}