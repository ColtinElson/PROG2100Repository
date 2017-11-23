#ifndef LAB4_HTMLCONVERTER_H
#define LAB4_HTMLCONVERTER_H

#include <iostream>

using namespace std;

class HTMLConverter {

public:
    static bool checkInputFileName(string name);

    static bool checkOutputFileName(string name);

    static bool readFile(string name);

    static string writeToFile(string inputName, string outputName);

    static string convertLine(string line);
};


#endif //LAB4_HTMLCONVERTER_H
