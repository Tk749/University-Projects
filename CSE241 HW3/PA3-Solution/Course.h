#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<string>
#include"Student.h"

using namespace std;


namespace PA3{
    class Student;
    
    class Course
    {

    public:
        Course();
        Course(string c_name, string c_code);

        void setname(string c_name);
        string getname();
        void setcode(string c_code);
        string getcode();
        int getsize();


        void add_student(string s_name, int s_id);
        void delete_student(string s_name, int s_id);
        void list_student();
        
        int student_finder(string s_name, int s_id);


    private:
        string code;
        string name;
        Student* Students;
        Student* temp;
        int size;
    };
    
};

#endif