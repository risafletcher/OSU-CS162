/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/13/19
** Description:  A function that takes an input stream variable and a pointer
**               to an array of integers that will contain the frequencies of
**               letters. It reads the paragraph from the input stream, counts
**               the frequencies, and pushes them to the array.
*******************************************************************************/

#include <fstream>

void count_letters(std::ifstream &, int*);