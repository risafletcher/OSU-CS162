/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  A program that performs sorting and searching for given files
*******************************************************************************/
#include "searchAndSort.hpp"
#include <iostream>


int main()
{
    SearchAndSort searchAndSort;

    std::cout << "\nSIMPLE SEARCH" << std::endl;
    std::cout << "---------------------" << std::endl;
    searchAndSort.simpleSearch();

    std::cout << "\nSORTING" << std::endl;
    std::cout << "---------------------" << std::endl;
    searchAndSort.sort();

    std::cout << "\nBINARY SEARCH" << std::endl;
    std::cout << "---------------------" << std::endl;
    searchAndSort.binary();

    return 0;
}