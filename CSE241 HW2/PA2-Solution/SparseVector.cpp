#include"SparseVector.h"
#include<iostream>

vec val;

SparseVector::SparseVector(){}

SparseVector::SparseVector(string txt){ // takes the SparseVector information from the file

    ifstream taka;
    taka.open(txt);

    int  a;
    double d;
    char c;

    while(1){ //assigns information from file to SparseVector
    
        taka >> a;
        if(check_errors(&taka)) break;
        val.index = a;

        taka >> c;

        taka >> d;
        val.data = d;
        if(check_errors(&taka)) break;

        vect.push_back(val);
    }
    taka.close();
}

int SparseVector::check_errors(ifstream* f) {// file error check
    int stop = 0;
    if (f->eof()) {
    stop = 0;
    }
    if (f->fail()) {
    stop = 1;
    }
    if (f->bad()) {
    stop = 1;
    }
    return stop;
}

SparseVector operator+(const SparseVector& x, const SparseVector& y){// Adds two SparseVectors

    SparseVector temp;

    int n1=0, n2=0;

    while(n1 != -1 || n2 != -1){

        if(x.vect[n1].index < y.vect[n2].index && n1 != -1 ){

            val.index  = x.vect[n1].index;
            val.data   = x.vect[n1].data;
            ++n1;
        }
        else if(x.vect[n1].index > y.vect[n2].index && n2 != -1 ){

            val.index = y.vect[n2].index;
            val.data  = y.vect[n2].data;
            ++n2;
        }
        else if(x.vect[n1].index == y.vect[n2].index && n1 != -1 && n2 != -1){

            val.index = x.vect[n1].index;
            val.data  = x.vect[n1].data + y.vect[n2].data;
            n1++;
            n2++;
        }

        temp.vect.push_back(val);

        if(x.vect.size() == n1) n1 = -1;
        if(y.vect.size() == n2) n2 = -1;
    }
    
    return temp;
}

SparseVector operator-(const SparseVector& x, const SparseVector& y){//Subtracts one SparseVector from another

    SparseVector temp;

    int n1=0, n2=0;

    while(n1 != -1 || n2 != -1){

        if(x.vect[n1].index < y.vect[n2].index && n1 != -1 ){

            val.index = x.vect[n1].index;
            val.data  = x.vect[n1].data;
            ++n1;
        }
        else if(x.vect[n1].index > y.vect[n2].index && n2 != -1 ){

            val.index = y.vect[n2].index;
            val.data  = -y.vect[n2].data;
            ++n2;
        }
        else if(x.vect[n1].index == y.vect[n2].index && n1 != -1 && n2 != -1){

            val.index = x.vect[n1].index;
            val.data  = x.vect[n1].data - y.vect[n2].data;
            n1++;
            n2++;
        }

        temp.vect.push_back(val);

        if(x.vect.size() == n1) n1 = -1;
        if(y.vect.size() == n2) n2 = -1;
    }
    
    return temp;
}

double dot(const SparseVector& x , const SparseVector& y){//Calculates the dot product(inner product) of two SparseVectors

    int n1=0, n2=0;
    double sum = 0;

    while(n1 != -1 && n2 != -1){

        if(x.vect[n1].index == y.vect[n2].index && n1 != -1 && n2 != -1){
            
            sum += x.vect[n1].data * y.vect[n2].data;
            ++n1;
            ++n2;
        }
        else if(x.vect[n1].index < y.vect[n2].index){

            ++n1;
        }
        else if(x.vect[n1].index > y.vect[n2].index){

            ++n2;
        }

        if(x.vect.size() == n1) n1 = -1;
        if(y.vect.size() == n2) n2 = -1;
    }
    return sum;
}

SparseVector& SparseVector::operator=(const SparseVector& x){// Assigns one SparseVector to another

    while(vect.size() != 0){

    vect.erase(vect.begin());
    }

    for(int i = 0; i < x.vect.size() ; ++i){

        val.index = x.vect[i].index;
        val.data = x.vect[i].data;

        vect.push_back(val);
    }
    return *this;
}

SparseVector operator-(const SparseVector& x){// Negates elements of a SparseVector 

    SparseVector temp = x;

    for(int i = 0; i < x.vect.size() ; ++i ){

        temp.vect[i].data = -1 * temp.vect[i].data;
    }
    return temp;
}

ostream& operator <<(ostream& os, const SparseVector& x){//Sends contents of a SparseVector to a std::ostream object.

    for (int i = 0 ; i < x.vect.size() ;++i){

        os << x.vect[i].index << ":" << x.vect[i].data << " ";
    }
    return os;
}
