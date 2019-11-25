/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  Specification file for searching and sorting algorithms
*******************************************************************************/
#ifndef SEARCH_AND_SORT_HPP
#define SEARCH_AND_SORT_HPP
#include <string>

class SearchAndSort
{
    struct File {
        int size;
        std::string name;
        int *array;
    };

    private:
        File files[4];
        File newFiles[4];
        void readFile(File*, std::string);
        int getValidInt();
        std::string fileNames[4] = {
            "original.txt",
            "early.txt",
            "middle.txt",
            "end.txt"};

    public:
        SearchAndSort();
        ~SearchAndSort();
        const int NUMBER_OF_FILES = 4;
        void simpleSearch();
        void sort();
        void binary();
        void selectionSort(File *, File *);
        void swap(int &, int &);
        void binarySearch(File *, int);
        void linearSearch(File*, int);
        void printArray(File*);
};

#endif