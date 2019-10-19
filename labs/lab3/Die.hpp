/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/20/19
** Description:  A program that accepts a text file and outputs the character
**               counts into new text files.
*******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    private:
        int n;  // number of sides on the individual die

    public:

        int randomInt();    // random int between 1 and n
};

#endif
