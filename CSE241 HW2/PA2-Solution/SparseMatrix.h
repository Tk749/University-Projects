#ifndef _SPARSE_MATRIX_H
#define _SPARSE_MATRIX_H

#include<vector>
#include<fstream>
#include<string>

using namespace std;

struct SMVector{
        int row;
        int index;
        double data;
};

class SparseMatrix{
private: 
    vector <SMVector> SMVec;
public:
    
    SparseMatrix();
    SparseMatrix(string txt);// takes the SparseMatrix information from the file
    int check_errors(ifstream *f);// file error check

    friend SparseMatrix operator + (const SparseMatrix& x, const SparseMatrix& y);// Adds two SparseMatrix
    friend SparseMatrix operator - (const SparseMatrix& x, const SparseMatrix& y);//Subtracts one SparseMatrix from another
    friend SparseMatrix operator * (SparseMatrix& x, SparseMatrix& y);// Multiplies two matrices
    friend SparseMatrix operator - (const SparseMatrix& x);// Negates elements of a SparseMatrix 
    friend ostream& operator << (ostream& os, const SparseMatrix& x); //Sends contents of a SparseMatrix to a std::ostream object. 
    SparseMatrix& operator = (const SparseMatrix& x);// Assigns one SparseMatrix to another

    SparseMatrix transpose ();

    double returndata(int r, int in);//return SMvec.data value
    int maxrow();//return max row value of matrix
    int maxindex();//return max index value of matrix
    int minindex(int a);//Return smallest index value less than a
};


#endif