#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Rational {
    //create private members for numerator and denominator
private:
    int numerator;
    int denominator;

    //create public members for everything else
public:
    Rational() //const with no args; sets rational to 0/1
        :numerator(0), denominator(1) {}

    explicit Rational(int wholeNum) //const with 1 arg; sets rational to whatever the user entered /1 (i.e 3/1)
        :numerator(wholeNum), denominator(1) {}

    Rational(int num, int denom) //const with 2 args; sets rational to whatever the user entered (i.e. 5/2)
            : numerator(num), denominator(denom) {}

    //Ensures only numerator is negative and that its as simple as possible
    static Rational normalize(int &num, int &denom) {
        //if the denominator is negative, multiply both top and bottom by -1
        if (denom < 0) {
            denom = (denom * -1);
            num = (num * -1);
        }
        //initialize greatest common factor (gcf) to be 1 as a standard (all numbers at least have 1 as a factor)
        int gcf = 1;
        //initialize the bigger number to be the denominator by default (a proper rational)
        int biggerNum = denom;
        //if the numerator is bigger (an improper rational) set the bigger number to numerator
        if (num / denom >= 1) {
            biggerNum = num;
        }
        //loop through every number consecutively until you reach the bigger number
        for (int i = 1; i <= biggerNum; i++) {
            //if both the numerator and the denominator are both divisible by that number, set gcf to that number
            if (abs(num) % i == 0 && abs(denom) % i == 0) {
                gcf = i;
            }
        }
        //divide numerator and denominator by that factor, simplifying it (i.e. 2/4 becomes 1/2)
        num = (num/gcf);
        denom = (denom /gcf);
    }

    //Define overloaded functions

    //overloaded +
    Rational operator+ (Rational rightNum)
    {
        //create a left number object
        int leftNumer = this-> numerator;
        int leftDenom = this->denominator;
        Rational leftNum(leftNumer, leftDenom);
        //get the denominator of the right object
        int rightDenom = rightNum.denominator;
        //if the two denominators are not equal to each other:
        if (leftDenom != rightDenom) {
            //multiply both the numerator and denominator by the opposite denominator
            // to ensure they're both over the same denominator (i.e. 1/4 and 2/3 would give you 3/12 and 8/12)
            leftNum.numerator = leftNum.numerator  * rightDenom;
            leftNum.denominator = leftNum.denominator * rightDenom;
            rightNum.numerator = rightNum.numerator * leftDenom;
            rightNum.denominator = rightNum.denominator * leftDenom;
        }
        //note: if the 2 denominators are equal to begin with, then no multiplying needs to be done

        //add both numerators together to make a new numerator, then keep the left number denominator
        // (since both denominators must be the same) to make a new rational object (3/12 + 8/12 = (3+8)/(12)
        Rational added(leftNum.numerator + rightNum.numerator, leftNum.denominator);
        //normalize the new number then return it
        normalize(added.numerator, added.denominator);
        return added;
    }

    //overloaded -
    Rational operator- (Rational rightNum)
    {
        //create a left number object
        int leftNumer = this-> numerator;
        int leftDenom = this->denominator;
        Rational leftNum(leftNumer, leftDenom);
        //get the denominator of the right object
        int rightDenom = rightNum.denominator;
        //if the two denominators are not equal to each other:
        if (leftDenom != rightDenom) {
            //multiply both the numerator and denominator by the opposite denominator
            // to ensure they're both over the same denominator (i.e. 1/4 and 2/3 would give you 3/12 and 8/12)
            leftNum.numerator = leftNum.numerator  * rightDenom;
            leftNum.denominator = leftNum.denominator * rightDenom;
            rightNum.numerator = rightNum.numerator * leftDenom;
            rightNum.denominator = rightNum.denominator * leftDenom;
        }
        //note: if the 2 denominators are equal to begin with, then no multiplying needs to be done

        //subtract the two numerators from each other and put them over the left numbers denominator
        // (since both denominators must be the same) to make a new rational (i.e. 8/12 - 3/12 = 5/12)
        Rational subtracted(leftNum.numerator - rightNum.numerator, leftNum.denominator);
        //normalize the new number and return it
        normalize(subtracted.numerator, subtracted.denominator);
        return subtracted;
    }

    //overloaded *
    Rational operator* (Rational rightNum)
    {
        //create a leftNum object
        Rational leftNum(this->numerator, this->denominator);
        //multiply the 2 numerators together and the 2 denominators together to make a new rational
        //(i.e. 2/3 * 4/5 = 8/15)
        Rational multiplied(leftNum.numerator * rightNum.numerator, leftNum.denominator * rightNum.denominator);
        //normalize the new number and return it
        normalize(multiplied.numerator, multiplied.denominator);
        return multiplied;
    }

    //overlaoded / (flips right number and calls overloaded *)
    Rational operator/ (Rational rightNum)
    {
        //create a left number object
        Rational leftNum(this->numerator, this->denominator);
        //initialze num and denom
        int num, denom;
        //if the right numerator does not equal 0
        if (rightNum.numerator != 0) {
            //create a temporary copy of the right num and denom
            num = rightNum.numerator;
            denom = rightNum.denominator;
            //switch the numerator and denominator of the right object (i.e. 3/2 is now 2/3)
            rightNum.numerator = denom;
            rightNum.denominator = num;
            //pass these new values into the multiplication function
            leftNum*rightNum;
        }
            //if the right number has 0 in the numerator, you can not divide the two numbers
        else {
            //display an error message to the user
            cout << "The right rational number can not have a 0 in its numerator (can't divide by 0)!" << endl;

            //temp code to flip left number instead. don't think this is right but have it just in case its what he wanted
//            num = leftNum.num;
//            denominator = leftNum.denominator;
//            leftNum.num = num;
//            leftNum.denominator = denominator;
//            leftNum*rightNum;
        }

    }

    //overloaded comparative operators

    //overloaded is equal to
    bool operator== (Rational rightNum)
    {
        //cross multiply the two rationals (i.e. a/b and c/d --> a*d and b*c)
        int cross1 = this->numerator * rightNum.denominator;
        int cross2 = this->denominator * rightNum.numerator;
        //return the result of checking to see if those two values are equal to each other
        return cross1 == cross2;
    }

    bool operator> (Rational rightNum)
    {
        //cross multiply the two rationals (i.e. a/b and c/d --> a*d and b*c)
        int cross1 = this->numerator * rightNum.denominator;
        int cross2 = this->denominator * rightNum.numerator;
        //return the result of checking to see if cross1 is bigger than cross2
        return cross1 > cross2;
    }

    bool operator< (Rational rightNum)
    {
        //cross multiply the two rationals (i.e. a/b and c/d --> a*d and b*c)
        int cross1 = this->numerator * rightNum.denominator;
        int cross2 = this->denominator * rightNum.numerator;
        //return the result of checking to see if cross1 is bigger than cross2
        return cross1 < cross2;
    }

    //implementation of friend functions

    //overloaded output function
    friend ostream& operator<<(ostream &output, Rational &number)
    {
        //if the denominator of the number is not 0 (got 0 if there was an error)
        if (number.denominator != 0) {
            //output the number as a rational (1/2)
            output << number.numerator << "/" << number.denominator;
        }
            //otherwise, don't do anything since that number shouldn't exist
        else {
            output << "";
        }
        //return the output ostream object
        return output;
    }

    //overloaded input function (reads in a string and gives back a rational object
    friend istream& operator>> (istream &input, Rational &number)
    {
        //initialize a string and valid boolean
        string str;
        bool valid;
        //loop until a usable number is input
        bool moveOn = false;
        while(moveOn == false) {
            //assign input to string variable
            input >> str;
            //if the number input has a / (a rational was input)
            if (str.find('/') != -1) {
                //split the string into a numerator and denominator
                string str1 = str.substr(0, str.find('/'));
                string str2 = str.substr(str.find('/') + 1);
                //check to see if either number is a decimal
                if (str1.find('.') == -1 && str2.find('.') == -1 ) {
                    //if not a decimal, try to put them into an int
                    try {
                        int num = stoi(str1);
                        int denom = stoi(str2);
                        //if the denominator entered was 0
                        if (denom == 0) {
                            //make the new number 0/1
                            denom = 1;
                            num = 0;
                        }
                        //create a rational with the entered numerator and denominator
                        number.numerator = num;
                        number.denominator = denom;
                        //since it's valid, move on
                        moveOn = true;
                        valid = true;
                    } catch (invalid_argument) { //if you can't get an int value: return false valid
                        valid = false;
                    }
                }
                    //if the number is a decimal: return false valid
                else {
                    valid = false;
                }
            }
                //if the number input does not have a / (whole number input not rational)
            else {
                try {
                    //try to put it into an int
                    int num = stoi(str);
                    //create a rational using that numerator and 1 as denominator (to make a whole number rational)
                    number.numerator = num;
                    number.denominator = 1;
                    //since its valid, move on
                    moveOn = true;
                    valid = true;
                } catch (invalid_argument) { //if you can't get an int value: return false valid
                    valid = false;
                }
            }

            //if the input is not valid:
            if (!valid)
            {
                //return error message
                cout << "You can't enter letters or decimals. Please try again:" << endl;
                //clear and ignore cin to get new input and reask user for input:
                cin.clear();
                cin.ignore(999,'\n');
            }
        }
        //return input istream object
        return input;
    }
};


