#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;
class Rational {
private:
    int num;
    int denom;

public:
    Rational() //const with no args
        :num(0), denom(1) {}

    explicit Rational(int wholeNum) //const with 1 arg
        :num(wholeNum), denom(1) {}

    Rational(int num, int denom) //const with 2 args
            : num(num), denom(denom) {}

    static Rational normalize(int &num, int &denom) {
        if (denom < 0) {
            denom = (denom * -1);
            num = (num * -1);
        }
        int gcf = 1;
        int biggerNum = denom;
        if (num / denom >= 1) {
            biggerNum = num;
        }
        for (int i = 1; i <= biggerNum; i++) {
            if (abs(num) % i == 0 && abs(denom) % i == 0) {
                gcf = i;
            }
        }
        num = (num/gcf);
        denom = (denom /gcf);
    }

    Rational operator+ (Rational &rightNum)
    {
        int leftDenom = this->denom;
        int rightDenom = rightNum.denom;
        if (leftDenom != rightDenom) {
            this->num = rightDenom * this->num;
            this->denom = rightDenom * this->denom;
            rightNum.num = leftDenom * rightNum.num;
            rightNum.denom = leftDenom * rightNum.denom;
        }


        Rational added(this->num + rightNum.num, this->denom);
        normalize(added.num, added.denom);
        return added;
    }

    Rational operator- (Rational &rightNum)
    {
        int leftDenom = this->denom;
        int rightDenom = rightNum.denom;
        if (leftDenom != rightDenom) {
            this->num = rightDenom * this->num;
            this->denom = rightDenom * this->denom;
            rightNum.num = leftDenom * rightNum.num;
            rightNum.denom = leftDenom * rightNum.denom;
        }


        Rational subtracted(this->num - rightNum.num, this->denom);
        normalize(subtracted.num, subtracted.denom);
        return subtracted;
    }

    Rational operator* (Rational &rightNum)
    {
        Rational multiplied(this->num * rightNum.num, this->denom * rightNum.denom);
        normalize(multiplied.num, multiplied.denom);
        return multiplied;
    }

    Rational operator/ (Rational &rightNum)
    {
        Rational leftNum(this->num, this->denom);
        int num, denom;
        if (rightNum.num != 0) {
            cout << "right flipped" << endl;
            num = rightNum.num;
            denom = rightNum.denom;
            rightNum.num = denom;
            rightNum.denom = num;
            leftNum*rightNum;
        }
        else if (leftNum.num != 0) {
            cout << "The right rational number can not have a 0 in its numerator (can't divide by 0)!" << endl;
//            cout << "left flip" << endl;
//            num = leftNum.num;
//            denom = leftNum.denom;
//            leftNum.num = num;
//            leftNum.denom = denom;
        }

    }

    bool operator== (Rational &rightNum)
    {
        normalize(this->num, this->denom);
        normalize(rightNum.num, rightNum.denom);
        int cross1 = this->num * rightNum.denom;
        int cross2 = this->denom * rightNum.num;
        return cross1 == cross2;
    }

    bool operator> (Rational &rightNum)
    {
        normalize(this->num, this->denom);
        normalize(rightNum.num, rightNum.denom);
        int cross1 = this->num * rightNum.denom;
        int cross2 = this->denom * rightNum.num;
        return cross1 > cross2;
    }

    bool operator< (Rational &rightNum)
    {
        normalize(this->num, this->denom);
        normalize(rightNum.num, rightNum.denom);
        int cross1 = this->num * rightNum.denom;
        int cross2 = this->denom * rightNum.num;
        return cross1 < cross2;
    }

    //implementation of friend function
    friend ostream& operator<<(ostream &output, Rational &number)
    {
        if (number.denom != 0) {
            output << number.num << "/" << number.denom;
        }
        else {
            output << "";
        }
        return output; //returns an ostream obj
    }

    friend istream& operator>> (istream &input, Rational &number)
    {
        string str;
        bool valid = false;
        bool moveOn = false;
        while(moveOn == false) {
            input >> str;//assign input to string var
            if (str.find('/') != -1) {
                string str1 = str.substr(0, str.find('/'));
                string str2 = str.substr(str.find('/') + 1);

                try {
                    int num = stoi(str1);
                    int denom = stoi(str2);
                    if (denom == 0) {
                        denom = 1;
                        num = 0;
                    }
                    number.num = num;
                    number.denom = denom;
                    moveOn = true;
                    valid = true;
                } catch (invalid_argument) {
                    valid = false;
                }
            }
            else {
                try {
                    int num = stoi(str);
                    number.num = num;
                    number.denom = 1;
                    moveOn = true;
                    valid = true;
                } catch (invalid_argument) {
                    valid = false;
                }
            }

            if (!valid)
            {
                cout << "You must type digits. Please try again:" << endl;
                cin.clear();
                cin.ignore(999,'\n');
            }
        }
        return input;
    }
};


