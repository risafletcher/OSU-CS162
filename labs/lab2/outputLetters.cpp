/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/13/19
** Description:  A function that takes an output stream variable and a pointer
**               to an array of integers that contains the frequencies of
**               letters. 
*******************************************************************************/

#include <fstream>
#include <iostream>
#include <string>

void output_letters(std::ofstream &ofs, int* letterCounts)
{
    const int ALPHABET_SIZE = 26;
    char alphabet[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::string outputFileName;

    std::cout << "Please enter a filename you'd like the count to output to: ";
    std::cin >> outputFileName;
    // pass in app flag so that every line is appended rather than overwritten 
    ofs.open(outputFileName.c_str(), std::ios::app);

    if (ofs.fail())
    {
        std::cout << "Error creating file." << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        // the indices should line up with the alphabetical order
        ofs << alphabet[i] << ": " << letterCounts[i] << std::endl;
    }
    // loop through array of letters in alphabetical order and output with
    // key_name: count
    ofs.close();
}