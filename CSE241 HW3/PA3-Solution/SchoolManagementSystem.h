#ifndef SCHOOLMANAGEMENTSYSTEM_H
#define SCHOOLMANAGEMENTSYSTEM_H

#include<iostream>
#include<string>
#include"Course.h"
#include"Student.h"

using namespace std;

namespace PA3{

    class Student;
    class Course;


    class SchoolManagementSystem{

    public:
        SchoolManagementSystem();

        void main_menu();
        void Student_menu();
        void Course_menu();

        void add_Sms_Student(string s_name, int s_id);
        void delete_Sms_Student(string s_name, int s_id);
        void list_Sms_Students();
        int Sms_Student_Finder(string s, int n);

        void drop_selected_student_from_a_course(string s, int n);
        bool drop(string s,string n,string s_name,int s_id);
        void add_selected_Student_to_a_course(string s_name,int s_id);

        void add_Sms_Courses(string c_name, string c_code);
        void delete_Sms_Courses(string c_name, string c_code);
        void list_Sms_Courses();
        int Sms_Courses_Finder(string c_name, string c_code);

        void list_students_registered_to_the_selected_course(string c_name, string c_code);
        void delete_crs_other_stu(string c_name, string c_code);

        bool h(string c_name, string c_code , string s_name ,int s_id);
        
    private:
        Student* Sms_Students;
        Student* temp_students;
        Course* Sms_Courses;
        Course* temp_courses;
        int Size_Students;
        int Size_Courses;
    };
}

#endif