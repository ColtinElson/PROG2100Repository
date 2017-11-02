#include <iostream>
#include <list>
#include "Rational.cpp"

int main() {
    Rational rational1;
    Rational rational2(3);
    Rational rational3(3,2);
    cout << "Rational made using default const: " << rational1 << endl;
    cout << "Rational made using whole number const: " << rational2 << endl;
    cout << "Rational made using numerator and denominator const: " << rational3 << endl;
    Rational rational4, rational5, rational6, rational7;
    cout << "Enter a rational number: " << endl;
    cin >> rational4;
    rational7 = rational4;
    cout << "Enter another rational number: " << endl;
    cin >> rational5;
    cout << "" << endl;
    cout << "Your two rational numbers: " << rational4 << " and " << rational5 << endl;

    cin.ignore();

    rational6 = rational4+rational5;
    cout << rational7 << " + " << rational5 << " = " << rational6 << endl;

    rational6 = rational4-rational5;
    cout << rational7 << " - " << rational5 << " = " << rational6 << endl;

    rational6 = rational4*rational5;
    cout << rational7 << " * " << rational5 << " = " << rational6 << endl;

    rational6 = rational4/rational5;
    cout << rational7 << " / " << rational5 << " = " << rational6 << endl;

    if (rational4 == rational5)
    {
        cout << rational7 << " is equal to " << rational5 << endl;
    }
    else if (rational4 > rational5)
    {
        cout << rational7 << " is greater than " << rational5 << endl;
    }
    else if (rational4 < rational5)
    {
        cout << rational7 << " is less than " << rational5 << endl;
    }
    cin.ignore();
    return 0;
}