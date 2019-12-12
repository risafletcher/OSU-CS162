/*********************************************************************
    ** Description: utility function for generating a select menu
    **              returns the index value of the selected option
*********************************************************************/
#include <string>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

int menu(string options[], int size)
{
    int selectedOption;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << options[i] << endl;
    }
    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (cin >> selectedOption &&
            selectedOption < size + 1 &&
            selectedOption != 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return selectedOption - 1;
}

int menuWithLabels(string options[], string labels[], int size)
{
    int selectedOption;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << options[i];
        cout << " (" << labels[i] << ")";
        cout << endl;
    }
    // loop until input is of valid int type
    while (true)
    {
        // since we're indexing at 1, we need to check for that
        if (cin >> selectedOption &&
            selectedOption < size + 1 &&
            selectedOption != 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return selectedOption - 1;
}
