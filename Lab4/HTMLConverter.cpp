#include "HTMLConverter.h"
#include <fstream>

using namespace std;

//check if input file is .cpp
bool HTMLConverter::checkInputFileName(string name) {
    bool valid = false;
    //get the length of the file name
    int length = name.length();
    //get the last 4 characters
    string extension = name.substr(length-4, length-1);
    //check to see if that substring is .cpp
    if (extension == ".cpp") {
        //if it is, its valid
        valid = true;
    }
    //otherwise, its not
    return valid;
}

//check if input file is .html
bool HTMLConverter::checkOutputFileName(string name) {
    bool valid = false;
    //get the length of the file name
    int length = name.length();
    //get the last 5 characters
    string extension = name.substr(length-5, length-1);
    //check to see if that substring is .html
    if (extension == ".html") {
        //if it is, its valid
        valid = true;
    }
    //otherwise, its not
    return valid;
}

//read in the file to ensure it actually exists
bool HTMLConverter::readFile(string name) {

    //create the ifstream
    ifstream inputFile;
    //set up the exceptions
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    //try to open the file
    //if it opens, return true otherwise return false;
    try {
        inputFile.open(name);
        return true;
    }
    catch(ifstream::failure&) {
        return false;
    }
}

//write to the file including converted strings
string HTMLConverter::writeToFile(string inputName, string outputName) {

    //open the input and output streams
    ifstream inputFile;
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    ofstream outputFile(outputName);

    try {
        //try to open the file
        inputFile.open(inputName);

        //if the file is open, continue on
        if (inputFile.is_open()) {
            string line;

            //if the output file doesn't fail, add a pre tag to the beginning
            if (!outputFile.fail()) {
                outputFile << "<PRE>" << endl;
            }
            //read in each line of the input file
            while (getline(inputFile,line)) {
                if (!inputFile.fail()) {
                    //send the line through the converter
                    line = HTMLConverter::convertLine(line);
                    if (!outputFile.fail()) {
                        //add the line to the output file
                        outputFile << line << endl;
                    }
                }
            }
            //if the output file doesn't fail, add a closing pre tag to the end
            if (!outputFile.fail()) {
                outputFile << "</PRE>" << endl;
            }
        }

        //close streams if they're open
        if (inputFile.is_open()) {
            inputFile.close();
        }
        if (outputFile.is_open()) {
            outputFile.close();
        }
    }
        //catch any errors if they exist
    catch(ifstream::failure&) {
        return "Bad input file";
    }

    //return file was written successfully
    return "\nFile written succesfully!";
}

//convert < to &lt; and > to &gt;
string HTMLConverter::convertLine(string line) {
    //assume there are some more chars to convert
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '<') {
            string sub1 = line.substr(0, i);
            string sub2 = line.substr(i+1);
            line = sub1 + "&lt;" + sub2;
        }
        if (line[i] == '>') {
            string sub1 = line.substr(0, i);
            string sub2 = line.substr(i+1);
            line = sub1 + "&gt;" + sub2;
        }
    }
//    bool moreChars = true;
//    //while there are some
//    while (moreChars) {
//        //get the position of <
//        size_t charFound = line.find('<');
//        //if one was found
//        if (charFound != string::npos) {
//            //replace < with &lt;
//            line.replace(charFound, 1, "&lt;");
//        }
//            //if none were found, move on
//        else {
//            moreChars = false;
//        }
//    }
//
//    //assume there are chars to convert
//    moreChars = true;
//    //while there are some
//    while (moreChars) {
//        //get the position of >
//        size_t charFound = line.find('>');
//        //if one was found
//        if (charFound != string::npos) {
//            //replace > with &gt;
//            line.replace(charFound, 1, "&gt;");
//        }
//            //if none were found, move on
//        else {
//            moreChars = false;
//        }
//    }

    //return the line
    return line;
}
