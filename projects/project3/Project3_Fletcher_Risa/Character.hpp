/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/10/19
** Description:  Specification for Character class (abstract)
*******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

using std::string;

class Character
{
    protected:
        string name, type;
        struct Die
        {
            int numberOfDie,
                numberOfSides;
        } attack, defense;
        int armor, strengthPoints;
        string characteristic;

    public:
        virtual int attackPlayer();
        virtual int defendPlayer();
        virtual void damage(int, int);
        int roll(Die);
        int getStrengthPoints();
        int getArmor();
        int getAttackNumDie();
        int getDefenseNumDie();
        int getAttackNumSides();
        int getDefenseNumSides();
        string getCharacteristic();
        string getName();
        string getType();
        void setName(string);
};

#endif