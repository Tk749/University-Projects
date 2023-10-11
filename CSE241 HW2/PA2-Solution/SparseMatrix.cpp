#include"SparseMatrix.h"
#include<iostream>

 SMVector value;

SparseMatrix::SparseMatrix(){}

SparseMatrix::SparseMatrix(string txt){// takes the SparseMatrix information from the file

    ifstream taka;
    taka.open(txt);

    string s1;
    int a;
    char c;
    double d;
    int i  = 0;
    
    while(1){//assigns information from file to SparseMatrix
    
    taka >> a;
    if(check_errors(&taka)) break;
    taka >> c;

    if(c == ':'){  

        value.index = a;
        taka >> d;
        value.data = d;

        SMVec.push_back(value);
    }
    else if('0' <= c && c <= '9'){

        value.row = a;
        i = 0;
        
        while(c != ':'){

            s1[i] = c;
            taka >> c;
            ++i;
        }
        a = stoi(s1);

        i = 0;

        while(s1[i] != '\0'){

            s1[i] = '\0';
            ++i;
        }

        value.index = a;
        taka >> d;
        value.data = d;

        SMVec.push_back(value);
    }

    if(check_errors(&taka)) break;
    }
    taka.close();
}

int SparseMatrix::check_errors(ifstream* f) {// file error check
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

SparseMatrix operator+(const SparseMatrix& x, const SparseMatrix& y){// Adds two SparseMatrix

    SparseMatrix temp;

    int n1=0, n2=0;

    value.row = 0;
    
    while(n1 != -1 || n2 != -1){
        if(n1 == -1){

            value.row = y.SMVec[n2].row;
            value.index = y.SMVec[n2].index;
            value.data = y.SMVec[n2].data;
            ++n2;            
        }
        else if(n2 == -1){

            value.row = x.SMVec[n1].row;
            value.index = x.SMVec[n1].index;
            value.data = x.SMVec[n1].data;
            ++n1;           
        }
        else if(x.SMVec[n1].row == y.SMVec[n2].row && n1 != -1 && n2 != -1 ){

            if(x.SMVec[n1].index == y.SMVec[n2].index){
                
                value.row   = x.SMVec[n1].row;
                value.index = x.SMVec[n1].index;
                value.data  = x.SMVec[n1].data + y.SMVec[n2].data;
                ++n1;
                ++n2;
            }
            else if(x.SMVec[n1].index > y.SMVec[n2].index && n2 != -1){

                value.row = y.SMVec[n2].row;
                value.index = y.SMVec[n2].index;
                value.data = y.SMVec[n2].data;
                ++n2;
            }
            else if(x.SMVec[n1].index < y.SMVec[n2].index && n1 != -1){

                value.row = x.SMVec[n1].row;
                value.index = x.SMVec[n1].index;
                value.data = x.SMVec[n1].data;
                ++n1;
            }       
        }
        else if (x.SMVec[n1].row > y.SMVec[n2].row && n2 !=-1)
        {
            value.row = y.SMVec[n2].row;
            value.index = y.SMVec[n2].index;
            value.data = y.SMVec[n2].data;
            ++n2;
        }
        else if (x.SMVec[n1].row < y.SMVec[n2].row && n1 !=-1)
        {
            value.row = x.SMVec[n1].row;
            value.index = x.SMVec[n1].index;
            value.data = x.SMVec[n1].data;
            ++n1;
        }

        temp.SMVec.push_back(value);

        if(x.SMVec.size()  == n1) n1 = -1;
        if(y.SMVec.size()  == n2) n2 = -1;
    }    
    return temp;
}

SparseMatrix operator-(const SparseMatrix& x, const SparseMatrix& y){//Subtracts one SparseMatrix from another

    SparseMatrix temp;

    int n1=0, n2=0;

    value.row = 0;
    
    while(n1 != -1 || n2 != -1){
        if(n1 == -1){

            value.row   =  y.SMVec[n2].row;
            value.index =  y.SMVec[n2].index;
            value.data  = -1*y.SMVec[n2].data;
            ++n2;            
        }
        else if(n2 == -1){

            value.row   = x.SMVec[n1].row;
            value.index = x.SMVec[n1].index;
            value.data  = x.SMVec[n1].data;
            ++n1;           
        }
        else if(x.SMVec[n1].row == y.SMVec[n2].row && n1 != -1 && n2 != -1 ){

            if(x.SMVec[n1].index == y.SMVec[n2].index){
                
                value.row   = x.SMVec[n1].row;
                value.index = x.SMVec[n1].index;
                value.data  = x.SMVec[n1].data - y.SMVec[n2].data;
                ++n1;
                ++n2;
            }
            else if(x.SMVec[n1].index > y.SMVec[n2].index && n2 != -1){

                value.row   = y.SMVec[n2].row;
                value.index = y.SMVec[n2].index;
                value.data  = -1*y.SMVec[n2].data;
                ++n2;
            }
            else if(x.SMVec[n1].index < y.SMVec[n2].index && n1 != -1){

                value.row   = x.SMVec[n1].row;
                value.index = x.SMVec[n1].index;
                value.data  = x.SMVec[n1].data;
                ++n1;
            }       
        }
        else if (x.SMVec[n1].row > y.SMVec[n2].row && n2 !=-1)
        {
            value.row   = y.SMVec[n2].row;
            value.index = y.SMVec[n2].index;
            value.data  = -1*y.SMVec[n2].data;
            ++n2;
        }
        else if (x.SMVec[n1].row < y.SMVec[n2].row && n1 !=-1)
        {
            value.row   = x.SMVec[n1].row;
            value.index = x.SMVec[n1].index;
            value.data  = x.SMVec[n1].data;
            ++n1;
        }

        temp.SMVec.push_back(value);

        if(x.SMVec.size()  == n1) n1 = -1;
        if(y.SMVec.size()  == n2) n2 = -1;
    }    
    return temp;
}

SparseMatrix operator - (const SparseMatrix& x){// Negates elements of a SparseMatrix 

    SparseMatrix temp = x;

    for(int i = 0; i < x.SMVec.size() ; ++i ){

        temp.SMVec[i].data = -1 * temp.SMVec[i].data;
    }

    return temp;
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix& x){// Assigns one SparseMatrix to another

    while(SMVec.size() != 0){

    SMVec.erase(SMVec.begin());
    }

    for(int i = 0; i < x.SMVec.size() ; ++i){
        value.row  = x.SMVec[i].row;
        value.index = x.SMVec[i].index;
        value.data = x.SMVec[i].data;

        SMVec.push_back(value);
    }
   
    return *this;

}

ostream& operator <<(ostream& os, const SparseMatrix& x){//Sends contents of a SparseMatrix to a std::ostream object. 

    for (int i = 0 ; i < x.SMVec.size() ;++i){
        
        if(i == 0){

            os << x.SMVec[i].row << " " ;
        }
        else if(x.SMVec[i-1].row != x.SMVec[i].row ){

            os << "\n" << x.SMVec[i].row << " ";
        }
        os << x.SMVec[i].index << ":" << x.SMVec[i].data << " ";
        
    }
    return os;
}

double SparseMatrix::returndata(int r,int in){//return SMvec.data value

    for(int i = 0 ; i< SMVec.size() ; ++i){

        if(SMVec[i].row == r){
            
            if(SMVec[i].index == in){

            return SMVec[i].data;
            }
        }

    }
    return 0;
}

int SparseMatrix::maxrow(){//return max row value of matrix

    int max=0;

    for(int i = 0; i < SMVec.size() ; ++i){

        if(max < SMVec[i].row) max = SMVec[i].row;
    }

    return max;

}

int SparseMatrix::maxindex(){//return max index value of matrix

    int max=0;

    for(int i = 0; i < SMVec.size() ; ++i){

        if(max < SMVec[i].index) max = SMVec[i].index;
    }

    return max;
}

int SparseMatrix::minindex(int min){//Return smallest index value less than a

    int a = maxindex();
    
    for (int i =0 ; i < SMVec.size() ; ++i){

        if(min < SMVec[i].index && SMVec[i].index < a )  a = SMVec[i].index ;
    
    }
    return a;
}

SparseMatrix operator * (SparseMatrix& x,SparseMatrix& y){// Multiplies two matrices
    SparseMatrix temp;
    int sizeRow;
    int sizeIndex;
    int size;
    if(x.maxrow() < y.maxrow() ){
        sizeRow = y.maxrow();
    }
    else sizeRow = x.maxrow();

    if(x.maxindex() < y.maxindex() ){
        sizeIndex = y.maxindex();
    }
    else sizeIndex = x.maxindex();

    if(sizeRow > sizeIndex){
        size = sizeRow;
    }
    else size = sizeIndex;

    int sum=0;
    for(int i = 1 ; i <= size ; ++i){

        for(int j = 1; j <= size ; ++j){

            sum = 0;
            for(int k = 1; k <=size ; ++k){
                
                sum += x.returndata(i,k) * y.returndata(k,j);
            }
            if(sum != 0){
                
                value.row = i;
                value.index = j;
                value.data = sum;
                temp.SMVec.push_back(value);
            }
        }
    }
    
    return temp;
}

SparseMatrix SparseMatrix::transpose (){//Returns the transpose of a matrix

    SparseMatrix temp;
    
    int mini= minindex(0);
    int item = 0;//number of sorted
    
    for(int i  = 0 ; item != SMVec.size() ; ++i){

        for(int j = 0 ; j < SMVec.size() ; ++j){

            if(SMVec[j].index == mini){

                value.row = SMVec[j].index;
                value.index = SMVec[j].row;
                value.data = SMVec[j].data;
                ++item;
                temp.SMVec.push_back(value);
            }

        }
        mini = minindex(mini);
    }

    return temp;
}
