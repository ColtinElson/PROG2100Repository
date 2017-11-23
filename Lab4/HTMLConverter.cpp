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
    }
    catch(ifstream::failure&) {
        valid = false;
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

            if (!outputFile.fail()) {
                outputFile << "<PRE>" << endl;
            }
            while (getline(inputFile,line)) {
                if (!inputFile.fail()) {
                    line = HTMLConverter::convertLine(line);
                    if (!outputFile.fail()) {
                        outputFile << line << endl;
                    }
                }
            }
            if (!outputFile.fail()) {
                outputFile << "</PRE>" << endl;
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

    return "\nFile written succesfully!";
}

string HTMLConverter::convertLine(string line) {
    bool moreChars = true;
    while (moreChars) {
        size_t charFound = line.find('<');
        if (charFound != string::npos) {
            line.replace(charFound, 1, "&lt;");
        }
        else {
            moreChars = false;
        }
    }

    moreChars = true;
    while (moreChars) {
        size_t charFound = line.find('>');
        if (charFound != string::npos) {
            line.replace(charFound, 1, "&gt;");
        }
        else {
            moreChars = false;
        }
    }

    return line;
}
