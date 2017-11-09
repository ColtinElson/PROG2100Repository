#ifndef __STUDENT_H_INCLUDED__   // if student.h hasn't been included yet...
#define __STUDENT_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include <iostream>
#include "Student.h"
using namespace std;

    Student::Student() //default constructor
            : max(5), courseCount(0), courseList(new string [max]) {}

    Student::Student(string studentName, string* courses) //constructor with student name and course array
            : max(5), name(studentName), courseList(courses), courseCount(static_cast<int>(courses->length())) {}

    Student::Student(const Student &student) {
        string *tempArray = new string[student.courseCount];
        for (int i = 0; i < student.courseCount; i++) {
            tempArray[i] = student.courseList[i];
            courseCount = i+1;
        }
        setCourseList(tempArray);
        max = courseCount + 5;
        name = student.name;
    }

    void Student::addCourse(string name) {
        courseList[courseCount] = name;
        courseCount++;
        if (courseCount == max) {
            max += 5;

            string *tempArray = new string[max];

            for (int i = 0; i < courseCount; i++) {
                tempArray[i] = courseList[i];
            }

            delete[]courseList;
            courseList = tempArray;
        }
    }

    string * Student::getCourseList() {
        return courseList;
    }

    string Student::printCourseList() {
        string courses;
        for (int i = 0; i < courseCount; i++) {
            courses += courseList[i];
            if (i < courseCount-1) {
                courses += ", ";
            }
        }
        return courses;
    }

    void Student::resetStudent() {
        courseCount = 0;
        setCourseList({});

    }

    //implementation of friend functions

    //overloaded output function
    ostream& operator<<(ostream &output, Student &student)
    {
        output << student.name << " is in " << student.courseCount << " courses: " << student.printCourseList();
        //return the output ostream object
        return output;
    }


const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getMax() {
    return max;
}

void Student::setMax(int max) {
    Student::max = max;
}

void Student::setCourseList(string *courseList) {
    Student::courseList = courseList;
}

int Student::getCourseCount(){
    return courseCount;
}

void Student::setCourseCount(int courseCount){
    Student::courseCount = courseCount;
}

#endif


