#ifndef __STUDENT_H_INCLUDED__   // if student.cpp hasn't been included yet...
#define __STUDENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
#include "Student.h"

using namespace std;
int main() {
    //loop through as needed
    bool repeat = true;
    while (repeat) {
        bool moveOn = false;
        //define variables for course name and student name
        string studentName;
        string course;
        //default constructor for student 1
        Student student1;
        //ask for name until user gives a value
        while (!moveOn) {
            cout << "What is your name?" << endl;
            getline(cin, studentName);
            if (!studentName.empty()) {
                student1.setName(studentName);
                moveOn = true;
            } else {
                cout << "You must type a name!" << endl;
            }

        }
        moveOn = false;
        //ask for courses until user hits done
        while (!moveOn) {
            cout << "Enter the courses you are in one at a time: If you are finished, type 'done'" << endl;
            getline(cin, course);
            if (course == "done") {
                moveOn = true;
            } else if (!course.empty()) {
                student1.addCourse(course);
            } else {
                cout << "You must put in a course name!" << endl;
            }
        }

        //output student 1
        cout << "Student 1: " << student1 << endl;
        //copy constructor to make student2
        Student student2(student1);
        //ask for name until user puts one in
        moveOn = false;
        while (!moveOn) {
            cout << "What is the second students name?" << endl;
            getline(cin, studentName);
            if (!studentName.empty()) {
                student2.setName(studentName);
                moveOn = true;
            } else {
                cout << "You must type a name!" << endl;
            }

        }
        //reset student 1
        student1.resetStudent();
        //print out student 2 and student1
        cout << "Student 1: " << student1 << endl;
        cout << "Student 2: " << student2 << endl;

        //default constructor student 3
        Student student3;
        //give them a name
        moveOn = false;
        while (!moveOn) {
            cout << "What is the third students name?" << endl;
            getline(cin, studentName);
            if (!studentName.empty()) {
                student3.setName(studentName);
                moveOn = true;
            } else {
                cout << "You must type a name!" << endl;
            }

        }
        //display with name
        cout << "Student 3: " << student3 << endl;
        //assign 3 to be student 2
        student3 = student2;
        //display them both
        cout << "Student 2: " << student2 << endl;
        cout << "Student 3: " << student3 << endl;
        //see if user wants to go again
        string response;
        cout << "\n" << "Would you like to go again?" << endl;
        cin >> response;
        if (response != "yes") {
            repeat = false;
        }
    }
    return 0;
}

#endif