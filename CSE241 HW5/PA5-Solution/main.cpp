#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"gates.h"

using namespace std;
using namespace PA5;


int main(){

    int size = 0;
    string a;

    ifstream taka;
    taka.open("input.txt");

    ifstream tk;
    tk.open("circuit.txt");

    string s;

    gates* *gate = new gates*[0];

    add_class(gate,size);
    gate[0] = new input(&tk);

    getline(tk,s);// takes OUTPUT and output names

    while(!tk.eof()){

        add_class(gate,size);
        tk >> s;
        if(s == "AND"){

            gate[size-1] = new AND(&tk);
        }
        else if(s == "OR"){

            gate[size-1] = new OR(&tk);
        }
        else if(s == "NOT"){

            gate[size-1] = new NOT(&tk);
        }
        else if(s == "FLIPFLOP"){

            gate[size-1] = new FLIPFLOP(&tk);
        }
        else if(s == "DECODER"){

            gate[size-1] = new DECODER(&tk);
        }
    }

    
    while(!taka.eof()){//prints the results of the input.txt values
        gate[0]->re(&taka);

        for(int i=1 ; i < size ; ++i){

            gate[i]->re();
        }
    }
}