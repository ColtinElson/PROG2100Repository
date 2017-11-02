#include <iostream>
#include <list>
#include "Rational.cpp"

int main() {
    //Create rationals using the 3 different constructors, for demo purposes
    Rational rational1;
    Rational rational2(3);
    Rational rational3(3,2);
    //display those rationals
    cout << "Rational made using default const: " << rational1 << endl;
    cout << "Rational made using whole number const: " << rational2 << endl;
    cout << "Rational made using numerator and denominator const: " << rational3 << endl;
    //loop until user decides to quit
    bool moveOn = false;
    while(!moveOn) {
        //create empty rational variables (default to 0/1)
        Rational rational4, rational5, rational6, rational7;
        //prompt the user to enter 2 rationals
        cout << "\nEnter a rational number: " << endl;
        cin >> rational4;
        rational7 = rational4;
        cout << "\nEnter another rational number: " << endl;
        cin >> rational5;
        cout << "" << endl;
        //display the user's rationals back to them,  to ensure they were made correctly
        cout << "Your two rational numbers: " << rational4 << " and " << rational5 << endl;

        cin.ignore();

        //run through operations in order: +, -, *, /, ==, >, and <
        //for each operation, display the whole equation (e.g. 1/2 + 2/4 = 1/1)
        rational6 = rational4 + rational5;
        cout << rational7 << " + " << rational5 << " = " << rational6 << endl;

        rational6 = rational4 - rational5;
        cout << rational7 << " - " << rational5 << " = " << rational6 << endl;

        rational6 = rational4 * rational5;
        cout << rational7 << " * " << rational5 << " = " << rational6 << endl;

        rational6 = rational4 / rational5;
        cout << rational7 << " / " << rational5 << " = " << rational6 << endl;

        if (rational4 == rational5) {
            cout << rational7 << " is equal to " << rational5 << endl;
        } else if (rational4 > rational5) {
            cout << rational7 << " is greater than " << rational5 << endl;
        } else if (rational4 < rational5) {
            cout << rational7 << " is less than " << rational5 << endl;
        }
        //ask the user if they would like to continue
        string cont;
        cout << "\nWould you like to run another calculation? (type y for yes or n for no)" << endl;
        cin >> cont;
        //if they don't, end the program
        if (cont == "n") {
            moveOn = true;
        }
        cin.ignore();
    }
    return 0;
}