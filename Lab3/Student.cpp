#ifndef __STUDENT_H_INCLUDED__   // if student.h hasn't been included yet...
#define __STUDENT_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include <iostream>
#include "Student.h"
using namespace std;

    Student::Student() //default constructor
            : max(5), courseCount(0), courseList(new string [max]) {}

    Student::Student(string studentName, string* courses) //constructor with student name and course array
            : max(5), name(studentName), courseList(courses), courseCount(static_cast<int>(courses->length())) {}

    Student::Student(const Student &student) //copy constructor
    {
        cout << "Copy constructor fired " << endl;
        string *tempArray = new string[student.courseCount];
        for (int i = 0; i < student.courseCount; i++) {
            tempArray[i] = student.courseList[i];
            courseCount = i+1;
        }
        setCourseList(tempArray);
        max = courseCount + 5;
        name = student.name;
    }

    Student::~Student() //destructor with not null check
    {
        cout << "Destructor fired " << endl;
        if (this != nullptr) {
            delete this;
        }
    }

    void Student::addCourse(string name) //add a course to the courselist
    {
        //add the course and increase the course count
        courseList[courseCount] = name;
        courseCount++;
        //if the new course count is equal to the max (size of list)
        if (courseCount == max) {
            //add 5 to the max to increase it
            max += 5;

            //create a new array with the new max size
            string *tempArray = new string[max];

            //assign new array all values of old array
            for (int i = 0; i < courseCount; i++) {
                tempArray[i] = courseList[i];
            }

            //delete old array and make new array equal to array
            delete[]courseList;
            courseList = tempArray;
        }
    }

    //print out the course list as a string
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

    //reset course count and course list
    void Student::resetStudent() {
        courseCount = 0;
        setCourseList({});

    }

    //overloaded assignment operator
    Student& Student::operator= (const Student &student) {
        cout << "assignment operator fired " << endl;
        courseCount = student.courseCount;
        courseList = student.courseList;
        name = student.name;
        max = courseCount + 5;
        return *this;
    }

    //implementation of friend functions

    //overloaded output function
    ostream& operator<<(ostream &output, Student &student)
    {
        output << student.name << " is in " << student.courseCount << " courses: " << student.printCourseList();
        //return the output ostream object
        return output;
    }


//getters and setters

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

string * Student::getCourseList() {
    return courseList;
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


