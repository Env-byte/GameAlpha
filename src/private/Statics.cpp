//
// Created by Tom Penn on 02/08/2022.
//

#include "Statics.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>

using namespace std;

int Statics::GetInput(const int &min, const int &max) {
    int option;
    string input;
    bool isValid;
    do {
        isValid = false;

        cout << "Please input your option" << endl;
        cin >> input;
        try {
            option = boost::lexical_cast<int>(input);
            if (option < min) {
                cout << option << "Input less than any menu option." << endl;
            } else if (option > max) {
                cout << option << "Input is greater than any menu option." << endl;
            } else {
                isValid = true;
            }
        }
        catch (boost::bad_lexical_cast &) {
            cout << "Invalid options." << endl;
        }
    } while (!isValid);
    return option;
}

void Statics::ClearConsole() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}
