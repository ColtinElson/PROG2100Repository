#ifndef __STUDENT_H_INCLUDED__   // if student.cpp hasn't been included yet...
#define __STUDENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>
#include "Student.h"

using namespace std;
int main() {
    bool moveOn = false;
    string studentName;
    string* courses;
    string course;
    Student student1;
    while (!moveOn) {
        cout << "What is your name?" << endl;
        getline(cin, studentName);
        if (!studentName.empty()) {
            student1.setName(studentName);
            moveOn = true;
        }
        else {
            cout << "You must type a name!" << endl;
        }

    }
    moveOn = false;
    while (!moveOn) {

        cout << "Enter the courses you are in one at a time: If you are finished, type 'done'" <<endl;
        getline(cin, course);
        if (course == "done") {
            moveOn = true;
        }
        else if (!course.empty()){
            student1.addCourse(course);
        }
        else {
            cout << "You must put in a course name!" << endl;
        }
    }
    cout << student1 << endl;
    Student student2(student1);
    moveOn = false;
    while (!moveOn) {
        cout << "What is the second students name?" << endl;
        getline(cin, studentName);
        if (!studentName.empty()) {
            student2.setName(studentName);
            moveOn = true;
        }
        else {
            cout << "You must type a name!" << endl;
        }

    }
    student1.resetStudent();
    cout << student1 << endl;
    cout << student2 << endl;

    Student student3 = student1;
    moveOn = false;
    while (!moveOn) {
        cout << "What is the third students name?" << endl;
        getline(cin, studentName);
        if (!studentName.empty()) {
            student3.setName(studentName);
            moveOn = true;
        }
        else {
            cout << "You must type a name!" << endl;
        }

    }

    cout << student2 << endl;
    cout << student3 << endl;

    return 0;
}

#endif