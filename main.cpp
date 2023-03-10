// github.com/NoSkill33
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Windows.h"

using namespace std;

int main()
{
    int length, choice;
    string password = "";

    srand(time(NULL));

    SetConsoleTitleA("PasswordPlus - NoSkill33");

    cout << "Enter password length: ";
    cin >> length;

    cout << "Choose password type:" << endl;
    cout << "1 - letters only" << endl;
    cout << "2 - numbers only" << endl;
    cout << "3 - letters, numbers, and special characters" << endl;
    cout << "Choice: ";
    cin >> choice;

    for (int i = 0; i < length; i++)
    {
        int randNum;

        switch (choice)
        {
        case 1:
            randNum = rand() % 26 + 97;
            break;
        case 2:
            randNum = rand() % 10 + 48;
            break;
        case 3:
            randNum = rand() % 62;
            if (randNum < 26)
            {
                randNum += 97;
            }
            else if (randNum < 52)
            {
                randNum += 65 - 26;
            }
            else
            {
                randNum += 48 - 52;
            }
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
        }

        char randChar = static_cast<char>(randNum);
        password += randChar;
    }

    cout << "Generated password: " << password << endl;

    Sleep(15000);
    return 0;
}
