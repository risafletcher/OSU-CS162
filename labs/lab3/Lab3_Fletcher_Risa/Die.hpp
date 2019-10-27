/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A class that holds a number of die sides and provides a method
**               for a random "toss" which returns an int between 1 - N
*******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    public:
        int n;  // number of sides on the individual die
        Die();
        Die(int);
        int randomInt();
        int roll(); // random int between 1 and n
};

#endif
