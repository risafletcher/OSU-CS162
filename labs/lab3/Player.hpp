/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A Player class which contains information on die preference
**               and sides preference.
*******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
    private:
        bool hasLoadedDie;
        int numberOfSides;
        int roll;
        int totalScore;
        bool isWinner;

    public:
        void setLoadedDieStatus(bool);
        bool getLoadedDieStatus();
        void setNumberOfSides(int);
        int getNumberOfSides();
        void updateRoll(int);
        void updateTotalScore(int);
        int getRoll();
        int getTotalScore();
};

#endif