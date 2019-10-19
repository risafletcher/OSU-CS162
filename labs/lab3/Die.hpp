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
    private:
        int n;  // number of sides on the individual die

    public:
        Die(int);
        int randomInt(); // random int between 1 and n
};

#endif
