#ifndef GATES_H
#define GATES_H


#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

namespace PA5{


    class gates{
                    
        public:
            void new_name(string s);                 //add vector_name(string s) and add vector_value(-1)
            void set_value(string s,int n);          //find vector_name(string s) then change its_value
            void set_NameAndValue(string s, int n);  //add vector_name(string s) and add vector_value(int n)
            int getsize();                           //return vector_value size
            string get_name(int n);                  //return vector_name[n]
            int get_val(int n);                      //return vector_value[n]
            int value_finder(string s);              //Finds the value of a known vector_name(string s)
            virtual void re(){}                      //blank virtual function
            virtual void re(ifstream* f){};          //blank virtual function
    };

    class input: public gates{

        public:

            input(ifstream* f);  //read circuit.txt. Add input names to vector_name and vector_i_names
            void re(ifstream* f);//read input.txt. set input value 

        private:

            vector<string> i_names;// for input names
            vector<int> allValue;  // for values
    };

    class AND: public gates{

        public:

            AND(ifstream* f);      //read circuit.txt. add output name in vector_name keep input names to i_names
            void re();             //Set output value to vector_value

        private:

            void And(int a,int b); //And gate    
            string i_name[2];// for input names
            string o_name;   // for output name
    };

    class OR: public gates{

        public:

            OR(ifstream* f);       //read circuit.txt. add output name in vector_name keep input names to i_names
            void re();             //set output value to vector_value


        private:

            void Or(int a,int b);  //Or gate
            string i_name[2];//for input names
            string o_name;   //for output names
    };

    class NOT: public gates{

        public:

            NOT(ifstream* f);//read circuit.txt. add output name in vector_name keep input name to i_names
            void re();       //set output value to vector_value

        private:

            void Not(int a); //Not gate
            string i_name;//for input name
            string o_name;//for output names
    };

    class FLIPFLOP: public gates{

        public:

            FLIPFLOP(ifstream* f);//read circuit.txt. add output name in vector_name keep input name to i_names
            void re();            //set output value to vector_value


        private:

            void Flipflop(int a);
            string i_name;//input name
            int former_value;
            string o_name;//output name
    };

    class DECODER: public gates{

        public:

            DECODER(ifstream* f);//read circuit.txt.keep input names to i_names
            void re();           //print results


        private:

            void Decoder(int a, int b);
            string i_name[2];//input names
    };

    void add_class(gates* * &dizi,int &n);// add new class
};

#endif