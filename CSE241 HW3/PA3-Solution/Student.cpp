#include"Student.h"
#include"Course.h"
#include<iostream>

using namespace std;



namespace PA3{

    Student::Student(){

        name = "";
        ID = 0;
        size = 0;
    }

    Student::Student(string s_name, int s_id){

        name = s_name;
        ID = s_id;
        size = 0;
    }

    void Student::setname(string s_name){

        name = s_name;
    }

    void Student::setID(int s_id){

        ID = s_id;
    }

    string Student::getname(){

        return name;
    }

    int Student::getID(){

        return ID;
    }

    void Student::add_course(string c_name, string c_code){

        ++size;
        
        if(size == 1){

            Courses = new Course[1];

            Courses[0].setname(c_name);
            Courses[0].setcode(c_code);
        }

        else{

            temp = new Course[size];

            for(int i = 0; i < size -1;++i){

                temp[i].setname(Courses[i].getname());
                temp[i].setcode(Courses[i].getcode());
            }

            delete [] Courses;

            temp[size-1].setname(c_name);
            temp[size-1].setcode(c_code);

            Courses = new Course[size];

            for(int i = 0; i < size ;++i){

                Courses[i].setname(temp[i].getname());
                Courses[i].setcode(temp[i].getcode());
            }

            delete [] temp;

        }        
    }

    void Student::list_course(){

        for(int i =0 ; i < size ; i++){

            cout << i+1 << " " << Courses[i].getcode() << " " << Courses[i].getname() << endl;
        }
    }

    int Student::course_finder(string c_name,string c_code){

        for(int i = 0; i < size ; ++i){

            if(Courses[i].getname() == c_name && Courses[i].getcode() == c_code){

                return i;
            }
        }

        return -1;
    }

    void Student::delete_course(int n){

        delete_course(Courses[n].getname(),Courses[n].getcode());

    }
    
    void Student::delete_course(string c_name,string c_code){

        if(size == 0){

            return;
        }
        else{

            int cou_n = course_finder(c_name,c_code);

            if(cou_n == -1){

                return;
            }
            else{

                --size;

                temp = new Course[size];

                for(int i = 0, j=0; i < size +1 ; ++i, ++j){

                    if(cou_n != i){

                        temp[j].setname(Courses[i].getname());
                        temp[j].setcode(Courses[i].getcode());
                    }
                    else{

                        --j;
                    }
                }

                delete [] Courses;

                Courses = new Course[size];
                
                for(int i = 0; i < size ; ++i){

                    Courses[i].setname(temp[i].getname());
                    Courses[i].setcode(temp[i].getcode()); 
                }

                delete [] temp;
            }
        }
    }

    int Student::getsize(){
            
            return size;
        }

};