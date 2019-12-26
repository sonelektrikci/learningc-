#ifndef SCHOOLPROJECT_STUDENT_H
#define SCHOOLPROJECT_STUDENT_H

#include <iostream>
#include<string>
#include <list>

using namespace std;


class Student {
public:

    Student();
    void setStudentList(list<string>);
    list<string> &getStudentList() ;
    void setStudentName(string &a);
    string getStudentName() const;
    void studentMenu();
    void addStudent();
    void searchStudent();
    void displayAllStudents();
    void deleteStudent();

private:
    string studentName;
    list<string> studentList;
};


#endif //SCHOOLPROJECT_STUDENT_H