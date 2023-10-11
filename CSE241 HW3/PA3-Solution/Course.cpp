#include"Student.h"
#include"Course.h"
#include<iostream>

using namespace std;



namespace PA3{

    Course::Course(){

        name = "";
        code = "";
        size = 0;
    }

    Course::Course(string c_name, string c_code){

        name = c_name;
        code = c_code;
        size = 0;
    }

    void Course::setname(string c_name){

        name = c_name;
    }

    void Course::setcode(string c_code){

        code = c_code;
    }

    string Course::getname(){

        return name;
    }

    string Course::getcode(){

        return code;
    }

    int Course::getsize(){
            
        return size;
    }

    void Course::add_student(string s_name, int s_id){

        ++size;

        if(size == 1){

            Students = new Student[1];

            Students[0].setname(s_name);
            Students[0].setID(s_id);
        }

        else{

            temp = new Student[size];
        
            for(int i = 0; i < size -1;++i){

                temp[i].setname(Students[i].getname());
                temp[i].setID(Students[i].getID());
            
            }

            delete [] Students;

            temp[size-1].setname(s_name);
            temp[size-1].setID(s_id);

            Students = new Student[size];

            for(int i = 0; i < size ;++i){

                Students[i].setname(temp[i].getname());
                Students[i].setID(temp[i].getID());
            }

            delete [] temp;
        }
    }

    void Course::delete_student(string s_name, int s_id){

        if(size == 0){

            return;
        }

        else{

            int stu_n = student_finder(s_name,s_id);

            if(stu_n == -1){

                return;
            }
            
            else{

                --size;

                temp = new Student[size];

                for(int i = 0, j=0; i < size +1 ; ++i, ++j){

                    if(stu_n != i){

                        temp[j].setname(Students[i].getname());
                        temp[j].setID(Students[i].getID());
                    }
                    else{

                        --j;
                    }
                }

                delete [] Students;

                Students = new Student[size];
                
                for(int i = 0; i < size ; ++i){

                    Students[i].setname(temp[i].getname());
                    Students[i].setID(temp[i].getID()); 
                }

                delete [] temp;
            }
        }
    }

    int Course::student_finder(string s_name,int s_id){

        for(int i = 0; i < size ; ++i){

            if(Students[i].getname() == s_name && Students[i].getID() == s_id){

                return i;
            }
        }

        return -1;
    }

    void Course::list_student(){

        for(int i =0 ; i < size ; i++){

            cout << Students[i].getname() << " " << Students[i].getID() << endl;
        }
    }
};