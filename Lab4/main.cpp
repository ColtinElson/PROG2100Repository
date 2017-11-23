#ifndef __HTMLCONVERTER_H_INCLUDED__   // if student.cpp hasn't been included yet...
#define __HTMLCONVERTER_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
#include "HTMLConverter.h"
#include <iostream>

using namespace std;

int main() {
    bool moveOn = false;
    cout << "Welcome to the HTML Converter Program!" << endl;
    cout << "This program will read in a .cpp file in output a .html file that can be displayed in a browser." << endl;
    string inputFile;
    while (!moveOn) {
        cout << "\n\nPlease enter the name of the .cpp file you would like to read in: " << endl;
        cout << "NOTE: you must give the full file path of the file!!! (i.e. /home/Desktop/example.cpp)" << endl;
        getline(cin, inputFile);

        bool hasName = HTMLConverter::checkInputFileName(inputFile);
        bool fileExists = HTMLConverter::readFile(inputFile);

        if (!inputFile.empty() && hasName && fileExists) {
            moveOn = true;
        } else {
            cout << "You must type a valid file name!" << endl;
        }
    }
    moveOn = false;
    string outputFile;
    while (!moveOn) {
        cout << "\nPlease enter the name of the .html file you would like to output to: " << endl;
        cout << "NOTE: you must give the full file path of the file!!! (i.e. /home/Desktop/example.html)" << endl;
        getline(cin, outputFile);

        bool hasName = HTMLConverter::checkOutputFileName(outputFile);

        if (!outputFile.empty() && hasName) {
            moveOn = true;
        } else {
            cout << "You must type a valid file name!" << endl;
        }
    }

    HTMLConverter::writeToFile(inputFile, outputFile);
    return 0;
}

#endif