/*******************************************************************************
** Author:       Risa Fletcher
** Date:         10/13/19
** Description:  A program that accepts a text file and outputs the character
**               counts into new text files.
*******************************************************************************/

#include "countLetters.hpp"

#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string inputFile;
    std::string outputFile;
    int letterCount[26] = {0};

    std::cout << "Please enter the file name (followed by its extension) ";
    std::cout << "that you'd like to read: ";
    std::cin >> inputFile;

    std::ifstream ifs(inputFile.c_str());

    if (ifs.fail())
    {
        std::cout << "The file was not found." << std::endl;
        return 1;
    }

    count_letters(ifs, letterCount);

    // read file and count frequency of each letter
    // for every new line encounered '\n', stop and ask the user for an output filename
    // then, ouput the count to that file and move onto the next
    ifs.close();
    return 0;
}