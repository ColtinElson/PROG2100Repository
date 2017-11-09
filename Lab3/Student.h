#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <iostream>

using namespace std;

class Student {

private:
    string name;
    int max;
    string *courseList;
    int courseCount;

public:
    Student();

    Student(string studentName, string *courseNames);

    Student(const Student &student);

    string printCourseList();

    const string &getName() const;

    void setName(const string &name);

    int getMax();

    void setMax(int max);

    void setCourseList(string *courseList);

    int getCourseCount();

    void setCourseCount(int courseCount);

    void addCourse(string name);

    string *getCourseList();

    void resetStudent();

    void operator= (const Student &student) {
        Student temp;
        temp.courseCount = student.courseCount;
        temp.courseList = student.courseList;
        temp.name = student.name;
        temp.max = courseCount + 5;
    }

    friend ostream& operator<<(ostream &output, Student &student);

};


#endif //LAB3_STUDENT_H
