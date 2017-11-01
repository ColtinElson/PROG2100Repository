#include <iostream>
#include "Rational.cpp"

int main() {
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

    Rational rat4 = rat*rat2;
    Rational rat5 = rat*rat3;
    Rational rat6 = rat3*rat2;
    cout << rat4 << endl;
    cout << rat5 << endl;
    cout << rat6 << endl;

    return 0;
}