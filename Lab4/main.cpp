#ifndef __HTMLCONVERTER_H_INCLUDED__   // if student.cpp hasn't been included yet...
#define __HTMLCONVERTER_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
#include "HTMLConverter.h"

using namespace std;

int main() {
    //set move on to false
    bool moveOn = false;

    //display welcome message
    cout << "Welcome to the HTML Converter Program!" << endl;
    cout << "This program will read in a .cpp file in output a .html file that can be displayed in a browser." << endl;

    //ask user for input file name until its valid
    string inputFile;
    while (!moveOn) {
        //prompt user
        cout << "\n\nPlease enter the name of the .cpp file you would like to read in: " << endl;
        //tell user how file should be read
        cout << "NOTE: you must give the full file path of the file!!! (i.e. /home/Desktop/example.cpp)" << endl;
        //read in file name
        getline(cin, inputFile);

        //check if file name is valid and exists
        bool hasName = HTMLConverter::checkInputFileName(inputFile);
        bool fileExists = HTMLConverter::readFile(inputFile);

        //if valid and exists
        if (hasName && fileExists) {
            //move on
            moveOn = true;
            //otherwise reprompt user
        } else {
            cout << "You must type a valid file name!" << endl;
        }
    }

    //ask user for output file name and verify its a valid .html file
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

    //convert file to html file and write it to it
    HTMLConverter::writeToFile(inputFile, outputFile);

    //display end message for user
    cout << "File written succesfully!" << endl;
    return 0;
}

#endif