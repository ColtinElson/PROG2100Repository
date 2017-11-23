#include "HTMLConverter.h"
#include <iostream>
#include <fstream>

using namespace std;

bool HTMLConverter::checkInputFileName(string name) {
    bool valid = false;
    int length = name.length();
    string extension = name.substr(length-4, length-1);
    if (extension == ".cpp") {
        valid = true;
        cout << "valid" << endl;
    }

    return valid;
}

bool HTMLConverter::checkOutputFileName(string name) {
    bool valid = false;
    int length = name.length();
    string extension = name.substr(length-5, length-1);
    if (extension == ".html") {
        valid = true;
        cout << "valid" << endl;
    }

    return valid;
}

bool HTMLConverter::readFile(string name) {
    bool valid = false;

    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        inputFile.open(name);
        valid = true;
        cout << "file opened" << endl;
    }
    catch(ifstream::failure&) {
        valid = false;
        cout << "bad file" << endl;
    }

    return valid;
}

string HTMLConverter::writeToFile(string inputName, string outputName) {

    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    ofstream outputFile(outputName);

    try {
        inputFile.open(inputName);

        if (inputFile.is_open()) {
            string line;

            while (getline(inputFile,line)) {
                if (inputFile.eof()) {
                    return "file read!";
                }
                line = HTMLConverter::convertLine(line);
                outputFile << line << endl;
            }
        }

        if (inputFile.is_open()) {
            inputFile.close();
        }
        if (outputFile.is_open()) {
            outputFile.close();
        }
    }
    catch(ifstream::failure&) {
        return "Bad input file";
    }


    return "valid";
}

string HTMLConverter::convertLine(string line) {
    line.find()
    return line;
}
