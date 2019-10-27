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
        int totalScore = 0;

    public:
        void setLoadedDieStatus(bool);
        bool getLoadedDieStatus();
        void setNumberOfSides(int);
        int getNumberOfSides();
        void updateRoll(int);
        void updateTotalScore(int);
        void reset();
        int getRoll();
        int getTotalScore();
};

#endif