#include <iostream>
#include <list>
#include "Rational.cpp"

int main() {
    Rational rational1;
    Rational rational2(3);
    Rational rational3(3,2);
    cout << "Rational made using default const: " << rational1;
    cout << "Rational made using whole number const: " << rational2;
    cout << "Rational made using numerator and denominator const: " << rational3;
    Rational rational4, rational5, rational6;
    cout << "Enter a rational number: " << endl;
    cin >> rational4;
    cout << "Enter another rational number: " << endl;
    cin >> rational5;
    cout << "" << endl;

    rational6 = rational4+rational5;
    cout << rational4 << " + " << rational5 << " = " << rational6 << endl;

    rational6 = rational4-rational5;
    cout << rational4 << " - " << rational5 << " = " << rational6 << endl;

    rational6 = rational4*rational5;
    cout << rational4 << " * " << rational5 << " = " << rational6 << endl;

    rational6 = rational4/rational5;
    cout << rational4 << " / " << rational5 << " = " << rational6 << endl;

    if (rational4 == rational5)
    {
        cout << rational4 << " is equal to " << rational5 << endl;
    }
    else if (rational4 > rational5)
    {
        cout << rational4 << " is greater than " << rational5 << endl;
    }
    else if (rational4 < rational5)
    {
        cout << rational4 << " is less than " << rational5 << endl;
    }
//    Rational noArg;
//    Rational anArg(3);
//    Rational twoArg(3,2);
//    Rational negArg(-3,3);
//    Rational dobArg(-4,-5);
//    Rational oneArg(5,-15);
//
//    cout << noArg << endl;
//    cout << anArg << endl;
//    cout << twoArg << endl;
//    cout << negArg << endl;
//    cout << dobArg << endl;
//    cout << oneArg << endl;

//    Rational noArg;
//    cout << "Enter rational number" << endl;
//    cin >> noArg;
//    cout << noArg;

    Rational rat(3,3);
    Rational rat2(4,3);
    Rational rat3(5,4);
    Rational rat7(4,4);

//    Rational rat4 = rat/rat2;
//    Rational rat5 = rat/rat3;
//    Rational rat6 = rat3/rat2;
//    cout << rat4 << endl;
//    cout << rat5 << endl;
//    cout << rat6 << endl;

//    Rational rat8 = rat7/rat2;
//    Rational rat9 = rat2/rat7;
//    cout << rat8 << endl;
//    cout << rat9 << endl;

    if (rat > rat2) {
        cout << "rat is rat2" << endl;
    }
    else if (rat < rat2) {
        cout << "rat is rat7" << endl;
    }

    return 0;
}