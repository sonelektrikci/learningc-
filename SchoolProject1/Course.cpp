#include "Course.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
Course::Course()
{
}
void Course::setCourseList(map<string,int> a)
{
    courseList = a;
}
map<string,int> &Course::getCourseList()
{
    return courseList;
}
void Course::setCourseName(string &b)
{
    cout<<"Enter the course name"<<endl;
    cin >> b;
    int size = b.size();
    if(size > 0 && size<20)
        courseName = b;
    else
        cout<<"Please enter a name between 1-20 char"<<endl;
}
string Course::getCourseName() const
{
    return courseName;
}
void Course::setHours(int &a)
{
    cout<<"Enter the course hours"<<endl;
    cin >> a;
    if(a>0 && a<10)
        courseHours = a;
    else
        cout<<"Please enter hours between 1-10"<<endl;
}
int Course::getHours()
{
    return courseHours;
}

void Course::courseMenu()
{
    cout<<"\n\t ... MENU FOR COURSES..."<<endl;
    cout<<"\t1.Add a course..."<<endl;
    cout<<"\t2.Search a course..."<<endl;
    cout<<"\t3.Display all courses..."<<endl;
    cout<<"\t4.Delete the course..."<<endl;
    cout<<"\t5.EXIT..."<<endl;
    cout<<"\nEnter your decision"<<endl;

    int choise;
    cin>>choise;

    switch (choise)
    {
        case 1:
            addCourse();
            cout<<"If you want to see added courses,enter y or n (lowercase)"<<endl;
            char control;
            cin>>control;
            if(control == 'y')
                displayAllCourses();
            else if(control == 'n')
            {
                cout<<"Do you want to back course menu? Hit y or n"<<endl;
                char control1;
                cin>>control1;
                if(control1 == 'y')
                    courseMenu();
            }
            cout<<"If you want to go to menu, enter y"<<endl;
            char control2;
            cin>>control2;
            if(control2 == 'y')
                courseMenu();
            break;
        case 2:
            searchCourse();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control3;
            cin>>control3;
            if(control3 == 'y')
                courseMenu();
            break;
        case 3:
            displayAllCourses();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control4;
            cin>>control4;
            if(control4 == 'y')
                courseMenu();
            break;
        case 4:
            deleteCourse();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control5;
            cin>>control5;
            if(control5 == 'y')
                courseMenu();
            break;
        default:
            cout<<"You enter a wrong number.Please enter a correct number...";
    }
}

void Course::addCourse()
{
    map<pair<string,int>,pair<Array1,Array1> >::iterator it;
    string a;
    int b;
    int total;
    int courseAdd;
    cout<<"How many course you want to add?"<<endl;
    cin>>courseAdd;
    cout<<"Enter the name of course and number of hours"<<endl;
    for(int i=0;i<courseAdd;++i)
    {
        setCourseName(a);
        setHours(b);
        getCourseList().insert({a, b});
        total += getHours();
        matchMap.insert({make_pair(a,b),make_pair(day,dayHours)});
    }


    if(total > 30)
    {
        cout<<"Sorry!You can assign only 30 hours of courses\n\n"<<endl;
        cout<<"If you want to add courses again enter y"<<endl;
        char yes;
        cin>>yes;
        if(yes == 'y')
            addCourse();
        else
            cout<<"You entered a wrong char"<<endl;
    }
    else
        cout<<"You added the courses succesfully!"<<endl;

}
void Course::seeMap()
{
    map<pair<string,int>,pair<Array1 ,Array> >::iterator it;
    for(it=matchMap.begin();it!=matchMap.end();++it)
    {
        for(int i=0;i<5;++i)
        {
            cout<<(it->first).first<<"--->"<<(it->first).second<<"--->"<<(it->second).first[i]<<endl;
        }
    }
}

void Course::searchCourse()
{
    string searchCourse;
    cout<<"Enter the name of the course you want to search.."<<endl;
    cin>>searchCourse;
    map<string,int>::iterator courseLocation;

    courseLocation = courseList.find(searchCourse);
    if(courseLocation != courseList.end())
        cout<<"Okey!I found the course you want!"<<endl;
    else
        cout<<"Sorry!I can't found the course"<<endl;
}
void Course::displayAllCourses()
{

    map<string,int>::iterator displayCourses;
    if(getCourseList().size() == 0)
    {
        cout<<"Sorry there is no course in list"<<endl;
    }
    else
        cout<<"Courses:\t\t |\t\t Course Hours:\n"<<endl;
    for(displayCourses = getCourseList().begin();displayCourses!= getCourseList().end();++displayCourses)
    {
        cout<<displayCourses->first<<"\t\t\t\t\t"<<displayCourses->second<<endl;
    }
}
void Course::deleteCourse()
{
    string deleteCourse;
    cout<<"Enter the course ID you want to delete"<<endl;
    cin>>deleteCourse;
    map<string,int>::iterator location;
    location = getCourseList().find(deleteCourse);

    if(location !=getCourseList().end())
        getCourseList().erase(deleteCourse);
    else
        cout<<"I cant find the student. Please try again!"<<endl;
}




