#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include"Course.h"

using namespace std;

namespace PA3
{
    class Course;

    class Student
    {

    public:
        Student();
        Student(string s_name, int s_id);

        void setname(string s_name);
        string getname();
        void setID(int s_id);
        int getID();
        int getsize();        

        void add_course(string c_name, string c_code);
        void delete_course(string c_name, string c_code);
        void list_course();
        void delete_course(int n);

        int course_finder(string c_name, string c_code);

    private:
        int ID;
        string name;
        Course* Courses;
        Course* temp;
        int size;
    };
};

#endif