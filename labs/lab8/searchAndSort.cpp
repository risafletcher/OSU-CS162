/*******************************************************************************
** Author:       Risa Fletcher
** Date:         11/24/19
** Description:  Implementation file for searching and sorting algorithms
*******************************************************************************/
#include "searchAndSort.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <limits>

SearchAndSort::SearchAndSort()
{
    for (int i = 0; i < NUMBER_OF_FILES; ++i)
    {        
        readFile(&files[i], fileNames[i]);
        std::cout << "\nFile read successfully." << std::endl;
        printArray(&files[i]);
    }
}

SearchAndSort::~SearchAndSort()
{
    for (int i = 0; i < NUMBER_OF_FILES; ++i)
    {
        delete[] files[i].array;
        files[i].array = nullptr;
    }
}

void SearchAndSort::readFile(File *file, std::string fileName)
{
    std::fstream fileBody(fileName);

    if (fileBody.fail())
    {
        std::cout << fileName << " was not found." << std::endl;
    }

    int number;
    int index = 0;
    int size = 0;

    file->name = fileName;

    while (fileBody >> number)
    {
        size++;
    }
    fileBody.clear();
    fileBody.seekg(0);

    file->size = size;
    file->array = new int[size];
    
    while (fileBody >> number)
    {
        file->array[index] = number;
        index++;
    }
}

int SearchAndSort::getValidInt()
{
    int selectedOption;
    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (std::cin >> selectedOption)
        {
            break;
        }
        else
        {
            std::cout << "Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return selectedOption;
}

void SearchAndSort::simpleSearch()
{
    std::cout << "Please enter a target value to search for: ";
    
    int targetValue = getValidInt();

    for (int i = 0; i < NUMBER_OF_FILES; ++i)
    {
        linearSearch(&files[i], targetValue);
    }
}

void SearchAndSort::linearSearch(File *file, int target)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < file->size && !found)
    {
        if (file->array[index] == target)
        {
            found = true;
            position = index;
        }
        index++;
    }

    if (found)
        std::cout << file->name << ": target value found" << std::endl;
    else
        std::cout << file->name << ": target value not found" << std::endl;
}

void SearchAndSort::binary()
{
    std::cout << "Please enter a target value to search for: ";

    int targetValue = getValidInt();
    for (int i = 0; i < NUMBER_OF_FILES; ++i)
    {

        binarySearch(&newFiles[i], targetValue);
    }
}

// using binary search from book (p.617)
void SearchAndSort::binarySearch(File *file, int target)
{
    int first = 0,
        last = file->size - 1,
        middle,
        position = -1;

    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) /2;
        if (file->array[middle] == target)
        {
            found = true;
            position = middle;
        }
        else if (file->array[middle] > target)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    if (position != -1)
    {
        std::cout << file->name << ": target value found" << std::endl;
    }
    else
    {
        std::cout << file->name << ": target value not found" << std::endl;
    }
}

void SearchAndSort::printArray(File *file)
{
    std::cout << file->name << ": ";
    for (int i = 0; i < file->size; ++i)
        std::cout << file->array[i] << " ";
    std::cout << std::endl;
}

void SearchAndSort::sort()
{
    for (int i = 0; i < NUMBER_OF_FILES; ++i)
    {
        selectionSort(&files[i], &newFiles[i]);
    }
}

// see book p.632
void SearchAndSort::selectionSort(File *file, File *newFile)
{
    std::string newFileName;
    std::cout << "\nPlease provide a name (and file extension) for the sorted ";
    std::cout << file->name << " array: ";
    std::cin >> newFileName;
    std::cout << std::endl;
    std::ofstream newFileBody(newFileName);

    newFile->name = newFileName;
    newFile->size = file->size;

    if (newFileBody.is_open())
    {
        int newArray[file->size];
        for (int i = 0; i < file->size; ++i)
        {
            newArray[i] = file->array[i];
        }

        int minIndex, minValue;

        for (int start = 0; start < (file->size - 1); start++)
        {
            minIndex = start;
            minValue = newArray[start];
            for (int index = start + 1; index < file->size; index++)
            {
                if (newArray[index] < minValue)
                {
                    minValue = newArray[index];
                    minIndex = index;
                }
            }
            swap(newArray[minIndex], newArray[start]);
        }

        newFile->array = newArray;

        std::cout << "New array: ";
        for (int i = 0; i < file->size; ++i)
        {
            std::cout << newArray[i] << " ";
            newFileBody << newArray[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Error creating new file." << std::endl;
    }
}

void SearchAndSort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
