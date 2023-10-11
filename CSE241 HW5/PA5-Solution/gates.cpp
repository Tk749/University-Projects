#include"gates.h"

using namespace std;

namespace PA5{

    vector <int> value;  //keep names
    vector <string> name;//keep values associated with vector_name 

    void add_class(gates* * &dizi,int &n){//dynamic class
        
        gates* * temp = new gates*[n+1];

        for(int i= 0; i < n; ++i){

            temp[i] = dizi[i];
        }

        delete[] dizi;
        dizi = temp;
        temp = NULL;
        ++n;

    }

    void gates::new_name(string s){//add vector_name(string s) and add vector_value(-1)

        name.push_back(s);
        value.push_back(-1);
    }

    void gates::set_value(string s,int n){//find vector_name(string s) then change its_value


        for(int i = 0; i < getsize() ; ++i){

            if(s == name[i]){

                value[i] = n;
            }
        }
    }

    void gates::set_NameAndValue(string s, int n){//add vector_name(string s) and add vector_value(int n)

            name.push_back(s);
            value.push_back(n);
    }

    int gates::getsize(){//return vector_value size

        return value.size();
    }

    string gates::get_name(int n){//return vector_name[n]

        return name[n];
    }

    int gates::get_val(int n){//return vector_value[n]

        return value[n];
    }

    int gates::value_finder(string s){//return vector_value[n]

        for(int i = 0; i < getsize() ; ++i){

            if(s == name[i]){

                return value[i];
            }
        }
        return -1;
    }

//-------------------------INPUT----------------------------------------
    input::input(ifstream* f){//read circuit.txt. Add input names to vector_name and vector_i_names

        string s;

        getline(*f,s);

        string likeChar;
        string temp;

        s += " ";
        for(int i= 0; i<s.size() +1  ; ++i){//for file handling

            likeChar[0] = s[i];

            if(likeChar[0] != 32){

                temp += likeChar[0];
            }
            else{

                if(temp != "INPUT"){
                    i_names.push_back(temp);
                    new_name(temp);
                    temp.clear();
                }
                else{

                    temp.clear();
                }
            }
        }
    }

    void input::re(ifstream *f){//read input.txt. set input value 

        int n;

        for(int i=0 ; i < i_names.size(); ++i){

            * f >> n;
            set_value(i_names[i],n);
        }
    }
// ------------------------AND---------------------------------------- 

    AND::AND(ifstream* f){//read circuit.txt. add output name in vector_name keep input names to i_names

        string s;

        * f >> s;
        o_name = s;
        new_name(s);

        * f >> s;
        i_name[0] = s;
        * f >> s;
        i_name[1] = s;
    }

    void AND::re(){//Set output value to vector_value

        And(value_finder(i_name[0]),value_finder(i_name[1]));
    }
    void AND::And(int a, int b){//And gate
          

        if(a==1 && b == 1 )      set_value(o_name,1);
        else if(a==1 && b == 0 ) set_value(o_name,0);
        else if(a==0 && b == 1 ) set_value(o_name,0);
        else if(a==0 && b == 0 ) set_value(o_name,0);
    }

// ----------------------------OR-----------------------------------------------

    OR::OR(ifstream* f){//read circuit.txt. add output name in vector_name keep input names to i_names

        string s;

        * f >> s;
        o_name = s;
        new_name(s);

        * f >> s;
        i_name[0] = s;

        * f >> s;
        i_name[1] = s;
    }

    void OR::re(){//set output value to vector_value

        Or(value_finder(i_name[0]),value_finder(i_name[1]));
    }

    void OR::Or(int a, int b){//Or gate
        
        if(a==1 && b == 1 )      set_value(o_name,1);
        else if(a==1 && b == 0 ) set_value(o_name,1);
        else if(a==0 && b == 1 ) set_value(o_name,1);
        else if(a==0 && b == 0 ) set_value(o_name,0);
    }

// -------------------------NOT--------------------------------------------------

    NOT::NOT(ifstream* f){//read circuit.txt. add output name in vector_name keep input name to i_names

        string s;

        * f >> s;
        o_name = s;
        new_name(s);

        * f >> s;
        i_name = s;
    }

    void NOT::re(){//set output value to vector_value

        Not(value_finder(i_name));
    }
    void NOT::Not(int a){//Not gate

        if(a==0)      set_value(o_name,1);

        else if(a==1) set_value(o_name,0);
    }

// -------------------------FLIPFLOP--------------------------------------------------

    FLIPFLOP::FLIPFLOP(ifstream* f){//read circuit.txt. add output name in vector_name keep input name to i_names

        string s;

        * f >> s;
        o_name = s;
        new_name(s);

        * f >> s;
        i_name = s;

        former_value = 0;
    }

    void FLIPFLOP::re(){//set output value to vector_value

        Flipflop(value_finder(i_name));
    }

    void FLIPFLOP::Flipflop(int a){

        if(a==1 && former_value == 1 )      set_value(o_name,0);
        else if(a==1 && former_value == 0 ) set_value(o_name,1);
        else if(a==0 && former_value == 1 ) set_value(o_name,1);
        else if(a==0 && former_value == 0 ) set_value(o_name,0);

        former_value = value_finder(o_name);
    }

// ---------------------------------DECODER------------------------------------------
    

    DECODER::DECODER(ifstream* f){//read circuit.txt.keep input names to i_names

        string s;
        * f  >> s;
        * f  >> s;
        * f  >> s;
        * f  >> s;
        * f  >> s;
        i_name[0] = s;
        * f >> s;
        i_name[1] = s;
        
    }

    void DECODER::re(){//print results

        Decoder(value_finder(i_name[0]),value_finder(i_name[1]));
    }

    void DECODER::Decoder(int a,int b){

        if(a == 1 && b == 1){

            cout << "0 0 0 1" << endl;
        }
        else if(a == 1 && b == 0){

            cout << "0 0 1 0" << endl;
        }
        else if(a == 0 && b == 1){

            cout << "0 1 0 0" << endl;
        }
        else if(a == 0 && b == 0){

            cout << "1 0 0 0" << endl;
        }
    }

    
//----------------------------------------------------------------------------
}