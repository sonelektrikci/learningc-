#include "Student.h"
#include <iostream>
#include <string>
#include<list>
#include <algorithm>
using namespace std;


Student::Student()
{
}
void Student::setStudentList(list<string> a)
{
    studentList = a;
}
list<string> &Student::getStudentList()
{
    return studentList;
}
void Student::setStudentName(string &b)
{
    cout<<"Enter the student name"<<endl;
    cin >> b;
    int size = b.size();
    if(size > 0 && size<20)
        studentName = b;
    else
        cout<<"Please enter a name between 1-20 char"<<endl;
}
string Student::getStudentName() const
{
    return studentName;
}
void Student::studentMenu()
{
    cout<<"\n\t ... MENU FOR STUDENT...\n"<<endl;
    cout<<"\t1.Add a students..."<<endl;
    cout<<"\t2.Search a student..."<<endl;
    cout<<"\t3.Display all students..."<<endl;
    cout<<"\t4.Delete a student..."<<endl;
    cout<<"\t5.EXIT ...."<<endl;
    cout<<"\nEnter your decision"<<endl;

    int choise;
    cin>>choise;

    switch (choise)
    {
        case 1:
            addStudent();
            cout<<"If you want to see added students,enter y or n (lowercase)"<<endl;
            char control;
            cin>>control;
            if(control == 'y')
                displayAllStudents();
            else if(control == 'n')
            {
                cout<<"Do you want to back student menu? Hit y or n"<<endl;
                char control1;
                cin>>control1;
                if(control1 == 'y')
                    studentMenu();
            }
            cout<<"If you want to go to menu, enter y"<<endl;
            char control2;
            cin>>control2;
            if(control2 == 'y')
                studentMenu();
            break;
        case 2:
            searchStudent();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control3;
            cin>>control3;
            if(control3 == 'y')
                studentMenu();
            break;
        case 3:
            displayAllStudents();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control4;
            cin>>control4;
            if(control4 == 'y')
                studentMenu();
            break;
        case 4:
            deleteStudent();
            cout<<"If you want to go to menu, enter y"<<endl;
            char control5;
            cin>>control5;
            if(control5 == 'y')
                studentMenu();
            break;
        case 5:
            break;
        default:
            cout<<"You enter a wrong number.Please enter a correct number...";
    }
}


void Student::addStudent()
{
    int studentAdd;
    cout<<"How many student do you want to add?"<<endl;
    cin>>studentAdd;

    for(int i=0;i<studentAdd;++i)
    {
        string b;
        setStudentName(b);
        getStudentList().push_back(getStudentName());
    }
}
void Student::searchStudent()
{
    string searchStudent;
    cout<<"Enter the name of the student you want to search.."<<endl;
    cin>>searchStudent;
    list<string>::iterator location;
    location = find(getStudentList().begin(),getStudentList().end(),searchStudent);
    if(location != getStudentList().end())
        cout<<"Okey!I found the student you want!"<<endl;
    else
        cout<<"Sorry!I can't found the student"<<endl;
}

void Student::displayAllStudents()
{
    list<string>::iterator display;
    if(getStudentList().size() == 0)
        cout<<"Sorry there is no student in list"<<endl;
    else
        cout<<"Students:\n"<<endl;
    for(display = getStudentList().begin();display!= getStudentList().end();++display)
    {
        cout<<*display<<endl;
    }

}
void Student::deleteStudent()
{
    list<string>::iterator it;
    string deleteStudent;
    cout<<"Enter the student name you want to delete"<<endl;
    cin>>deleteStudent;
    list<string>::iterator location;
    location = find(getStudentList().begin(),getStudentList().end(),deleteStudent);

    if(location !=getStudentList().end())
        getStudentList().remove(deleteStudent);
    else
        cout<<"I cant find the student. Please try again!"<<endl;
}




