/*******************************************************************************
** Author:       Risa Fletcher
** Date:         12/8/19
** Description:  Utility functions for menu and input validation
*******************************************************************************/
#ifndef RECORD_HPP
#define RECORD_HPP
#include <string>

using std::string;

int getValidInt();
int getMenuOption(string options[], int size);
int mainMenu();

void printRow(  int N,
                unsigned long int val, 
                unsigned long int nonRecursive,
                unsigned long int recursive);
void getUserInput();
void test();
// source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
int fibonacciNonRecursive(const int &n);
int fibonacciRecursive(const int &n);

#endif