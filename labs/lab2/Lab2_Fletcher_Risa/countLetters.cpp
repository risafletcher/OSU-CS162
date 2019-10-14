/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/13/19
** Description:  A function that takes an input stream variable and a pointer
**               to an array of integers that will contain the frequencies of
**               letters. It reads the paragraph from the input stream, counts
**               the frequencies, and pushes them to the array.
*******************************************************************************/

#include "outputLetters.hpp"
#include <fstream>
#include <string>
#include <iostream>

void count_letters(std::ifstream &ifs, int* letterCounts)
{
    std::string line;
    const int ALPHABET_SIZE = 26;
    char alphabet[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char tempArray[ALPHABET_SIZE];

    std::cout << "For each paragraph in this file, you will be asked to provide an output ";
    std::cout << "file name." << std::endl;

    // read each line in the text file and iterate through each character in the string
    while (getline(ifs, line))
    {
        for (int i = 0; i < line.size(); ++i)
        {
            // iterate through each letter in the alphabet array and find a match
            // at that same index position in the letterCounts array, increment that count
            // this ensures the character counts line up
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                if (std::tolower(line[i]) == alphabet[j])
                    letterCounts[j]++;
            }
        }

        // output the counts into respective files
        std::ofstream ofs;
        output_letters(ofs, letterCounts);
        // reset letter counts array
        for (int k = 0; k < ALPHABET_SIZE; ++k)
            letterCounts[k] = 0;
    }
}