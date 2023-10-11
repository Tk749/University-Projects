#include"SchoolManagementSystem.h"
#include"Student.h"
#include"Course.h"
#include<iostream>

using namespace std;


namespace PA3
{
    SchoolManagementSystem::SchoolManagementSystem(){ 
        Size_Courses = 0;
        Size_Students = 0;
    }

    void SchoolManagementSystem::main_menu(){

        int Choice;

        cout << "Main_menu"<<endl;
        while(1){

            cout << "0 exit"<<endl
            << "1 student" << endl
            << "2 course" << endl
            << "3 list_all_students" << endl
            << "4 list_all_courses" << endl
            << ">>";
            cin >> Choice;

            if(Choice == 0){

                return;
            }
            else if(Choice == 1){

                Student_menu();
            }
            else if(Choice == 2){

                Course_menu();
            }
            else if(Choice == 3){

                list_Sms_Students();
            }
            else if(Choice == 4){

                list_Sms_Courses();
            }
        }
    }
    void SchoolManagementSystem::Student_menu(){

        int Choice;
        int s_id;
        string s_name;
        string temp;

        while(1){

            cout << "0 up"<<endl
            << "1 add_student"<<endl
            << "2 select_student"<< endl
            << ">>";
            cin >> Choice;
            if(Choice == 0){

                return;
            }
            else if(Choice == 1){

                cout << ">>";
                while(1){

                    cin >> temp;

                    if(temp[0] >= '0' && temp[0] <= '9'){

                        s_id = stoi(temp);
                        s_name[(int)(s_name.size())-1] = '\0';
                        break;
                    }
                    else{

                        s_name += temp;
                        s_name += " ";
                    }
                }
                add_Sms_Student(s_name,s_id);
            }
            else if(Choice == 2){

                cout << ">>";
                while(1){

                    cin >> temp;

                    if(temp[0] >= '0' && temp[0] <= '9'){

                        s_id = stoi(temp);
                        s_name[(int)(s_name.size())-1] = '\0';
                        break;
                    }
                    else{

                        s_name += temp;
                        s_name += " ";
                    }
                }


                
                while(1){
                    cout << "0 up"<< endl
                    << "1 delete_student" << endl
                    << "3 add_selected_Student_to_a_course" << endl
                    << "4 drop_selected_student_from_a_course" <<endl
                    << ">>" ;
                    cin >> Choice;

                    if(Choice == 0){

                        break;
                    }
                    else if(Choice == 1){

                        delete_Sms_Student(s_name,s_id);
         
                        break;
                    }
                    else if(Choice == 3){

                        add_selected_Student_to_a_course(s_name,s_id);
                    }
                    else if(Choice == 4){

                        drop_selected_student_from_a_course(s_name,s_id);
                    }
                }
            }
        }
    }
    void SchoolManagementSystem::Course_menu(){

        int Choice;
        string c_code;
        string c_name;
        string temp;

        while(1){

            cout << "0 up"<<endl
            << "1 add_course"<<endl
            << "2 select_course"<< endl
            << ">>";
            cin >> Choice;

            if(Choice == 0){

                break;
            }         
            else if(Choice == 1){

                cout << ">>";
                c_name = "";
                cin >> c_code;
                getline(cin,temp);
                for(int i = 0; i < (int)(temp.size())-1;++i){

                    c_name += temp[i+1];
                }
                
                add_Sms_Courses(c_name,c_code);
            }
            else if(Choice == 2){

                cout << ">>";
                c_name = "";
                cin >> c_code;
                getline(cin,temp);
                for(int i = 0; i < (int)(temp.size())-1;++i){

                    c_name += temp[i+1];
                }
                

                while(1){

                    cout << "0 up"<< endl
                    << "1 delete_course" << endl
                    << "2 list_students_registered_to_the_selected_course" << endl
                    << ">>" ;
                    cin >> Choice;

                    if(Choice == 0){

                        break;
                    }         
                    else if(Choice == 1){

                        delete_Sms_Courses(c_name,c_code);
                        break;
                    }       
                    else if(Choice == 2){

                        list_students_registered_to_the_selected_course(c_name,c_code);
                    }
                }
            }   
        }
    }

    void SchoolManagementSystem::add_Sms_Student(string s_name, int s_id){

        ++Size_Students;
        
        if(Size_Students == 1){

            Sms_Students = new Student[1];

            Sms_Students[0].setname(s_name);
            Sms_Students[0].setID(s_id);
        }

        else{

            temp_students = new Student[Size_Students];
            


            for(int i = 0; i < Size_Students -1;++i){

                temp_students[i].setname(Sms_Students[i].getname());
                temp_students[i].setID(Sms_Students[i].getID());
            }
            delete [] Sms_Students;

            temp_students[Size_Students-1].setname(s_name);
            temp_students[Size_Students-1].setID(s_id);


            Sms_Students = new Student[Size_Students];

            for(int i = 0; i < Size_Students ;++i){

                Sms_Students[i].setname(temp_students[i].getname());
                Sms_Students[i].setID(temp_students[i].getID());
            }

            delete [] temp_students;
        }
    }

    void SchoolManagementSystem::list_Sms_Students(){

        for(int i=0 ; i < Size_Students;++i){

            cout << Sms_Students[i].getname() << " " << Sms_Students[i].getID() << endl;
        }
    }

    void SchoolManagementSystem::delete_Sms_Student(string s_name, int s_id){

        if(Size_Students == 0){

            return;
        }
        else{

            int stu_n = Sms_Student_Finder(s_name,s_id);

            if(stu_n == -1){

                return;
            }
            else{

                --Size_Students;

                temp_students = new Student[Size_Students];

                for(int i = 0, j=0; i < Size_Students +1 ; ++i, ++j){

                    if(stu_n != i){

                        temp_students[j].setname(Sms_Students[i].getname());
                        temp_students[j].setID(Sms_Students[i].getID());
                    }
                    else{

                        --j;
                    }
                }

                delete [] Sms_Students;

                Sms_Students = new Student[Size_Students];
                
                for(int i = 0; i < Size_Students ; ++i){

                    Sms_Students[i].setname(temp_students[i].getname());
                    Sms_Students[i].setID(temp_students[i].getID()); 
                }

                delete [] temp_students;
            }
        }
    }

    int SchoolManagementSystem::Sms_Student_Finder(string s_name, int s_id){

        for(int i = 0; i < Size_Students ; ++i){

            if(Sms_Students[i].getname() == s_name && Sms_Students[i].getID() == s_id){

                return i;
            }
        }

        return -1;
    }

    void SchoolManagementSystem::drop_selected_student_from_a_course(string s_name, int s_id){

        int num;
        int stu_n = Sms_Student_Finder(s_name,s_id);

        if(stu_n == -1){

            return;
        }
        else{

            if(Sms_Students[stu_n].getsize() == 0){

                return;
            }
            cout << "0 up" << endl;
            Sms_Students[stu_n].list_course();

            cout<<">>";
            cin >> num;

            if( num == 0){

                return;
            }

            Sms_Students[stu_n].delete_course(num-1);
        }
    }

    void SchoolManagementSystem::add_selected_Student_to_a_course(string s_name, int s_id){

        if(Size_Courses == 0){

            return;
        }

        cout << "0 up" << endl;

        for(int i= 0,j =0 ; i < Size_Courses ; ++i, ++j){

            if(drop(Sms_Courses[i].getname(),Sms_Courses[i].getcode(),s_name,s_id)){

                cout << j+1 << " " << Sms_Courses[i].getcode() << " " << Sms_Courses[i].getname() << endl;
            }
            else{
                --j;
            }
        }

        int num;

        cout <<">>";
        cin >> num;

        for(int i= 0, j = 0 ; i <Size_Courses ; ++i , ++j){

            if(drop(Sms_Courses[i].getname(),Sms_Courses[i].getcode(),s_name,s_id)){

                if(j+1 == num){

                    int stu_n = Sms_Student_Finder(s_name,s_id);

                    if( s_id != -1){

                        Sms_Students[stu_n].add_course(Sms_Courses[i].getname(),Sms_Courses[i].getcode());
                    }
                }
            }
            else{
                --j;
            }

        }
    }

    bool SchoolManagementSystem::drop(string s, string n, string s_name, int s_id){
        
        int stu_n = Sms_Student_Finder(s_name,s_id);
        if(stu_n != -1){

            if( Sms_Students[stu_n].course_finder(s,n) != -1){

                return false;
            }
                
            return true;
        }
        return false;
    }

    void SchoolManagementSystem::add_Sms_Courses(string c_name, string c_code){

        ++Size_Courses;
        
        if(Size_Courses == 1){

            Sms_Courses = new Course[1];

        Sms_Courses[0].setname(c_name);
        Sms_Courses[0].setcode(c_code);
        }

        else{

        temp_courses = new Course[Size_Courses];

        for(int i = 0; i < Size_Courses -1;++i){

            temp_courses[i].setname(Sms_Courses[i].getname());
            temp_courses[i].setcode(Sms_Courses[i].getcode());
        }
        delete [] Sms_Courses;

        temp_courses[Size_Courses-1].setname(c_name);
        temp_courses[Size_Courses-1].setcode(c_code);


        Sms_Courses = new Course[Size_Courses];

        for(int i = 0; i < Size_Courses ;++i){

            Sms_Courses[i].setname(temp_courses[i].getname());
            Sms_Courses[i].setcode(temp_courses[i].getcode());
        }

        delete [] temp_courses;

        }  
    }

    void SchoolManagementSystem::list_Sms_Courses(){

        for(int i =0 ; i < Size_Courses ; i++){

            cout << Sms_Courses[i].getcode() << " " << Sms_Courses[i].getname() << endl;
        }
    }

    void SchoolManagementSystem::delete_Sms_Courses(string c_name, string c_code){

        if(Size_Courses == 0){

            return;
        }
        else{

            int cou_n = Sms_Courses_Finder(c_name,c_code);

            if(cou_n == -1){

                return;
            }
            else{

                --Size_Courses;

                temp_courses = new Course[Size_Courses];

                for(int i = 0, j=0; i < Size_Courses +1 ; ++i, ++j){

                    if(cou_n != i){

                        temp_courses[j].setname(Sms_Courses[i].getname());
                        temp_courses[j].setcode(Sms_Courses[i].getcode());
                    }
                    else{

                        --j;
                    }
                }

                delete [] Sms_Courses;

                Sms_Courses = new Course[Size_Courses];
                
                for(int i = 0; i < Size_Courses ; ++i){

                    Sms_Courses[i].setname(temp_courses[i].getname());
                    Sms_Courses[i].setcode(temp_courses[i].getcode()); 
                }

                delete [] temp_courses;

                delete_crs_other_stu(c_name,c_code);
            }
        }
    }

    int SchoolManagementSystem::Sms_Courses_Finder(string c_name, string c_code){

        for(int i = 0; i < Size_Courses ; ++i){

            if(Sms_Courses[i].getname() == c_name && Sms_Courses[i].getcode() == c_code){

                return i;
            }
        }

        return -1;
    }

    void SchoolManagementSystem::list_students_registered_to_the_selected_course(string c_name, string c_code){

        int cou_n = Sms_Courses_Finder(c_name,c_code);

        if(cou_n != -1){

            for(int i= 0, j= 0; i < Size_Students ; ++i,++j ) {

                if(Sms_Students[i].getsize() != 0){

                    if(h(c_name,c_code,Sms_Students[i].getname(),Sms_Students[i].getID())){

                        cout << j+1 << " " << Sms_Students[i].getname() << " " << Sms_Students[i].getID()<< endl;
                    }
                }
                else{

                    --j;
                }
            }
        }


        return;

    }

     bool SchoolManagementSystem::h(string c_name, string c_code , string s_name ,int s_id){

        int stu_n = Sms_Student_Finder(s_name,s_id);

        if(stu_n != -1){


            if(Sms_Students[stu_n].course_finder(c_name,c_code) != -1){

                return true;
            }
        }
         return false;
     }

     void SchoolManagementSystem::delete_crs_other_stu(string c_name, string c_code){


         for(int i=0 ; i <Size_Students ; ++i){

             if(Sms_Students[i].getsize() != 0){

                Sms_Students[i].delete_course(c_name,c_code);
             }
         }
     }

};
