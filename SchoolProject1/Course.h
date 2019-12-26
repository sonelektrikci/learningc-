#ifndef SCHOOLPROJECT_COURSE_H
#define SCHOOLPROJECT_COURSE_H

#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
//typedef array<int,6> Array;
//typedef array<string,6> Array1;
using namespace std;

class Course {
public:
    //For Course
    Course();
    void setCourseList(map<string,int>);
    map<string,int> &getCourseList();
    void setCourseName(string &);
    string getCourseName() const;
    void setHours(int &);
    int getHours();
    void courseMenu();
    void addCourse();
    void searchCourse();
    void deleteCourse();
    void displayAllCourses();
    void seeMap();


private:
    string courseName;
    int courseHours;
    map<string,int> courseList;

    //Array dayHours{0,0,0,0,0,0};
    //Array1 day{"Monday","Tuesday","Wednesday","Thursday","Friday"};
    list<char>days{6};
    map<pair<string,int>,list<string> > matchMap;
};


#endif //SCHOOLPROJECT_COURSE_H
