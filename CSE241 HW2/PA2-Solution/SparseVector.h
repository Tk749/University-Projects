#ifndef _COMPLEX_H
#define _COMPLEX_H

#include<vector>
#include<fstream>
#include<string>

using namespace std;

struct vec{
        int index;
        double data;
};

class SparseVector{
private: 
    vector <vec> vect;   
public:

    SparseVector();
    SparseVector(string txt); // takes the SparseVector information from the file
    int check_errors(ifstream *f); // file error check

    friend SparseVector operator+ (const SparseVector&, const SparseVector&);// Adds two SparseVectors
    friend SparseVector operator-(const SparseVector& x, const SparseVector& y); //Subtracts one SparseVector from another
    friend SparseVector operator-(const SparseVector& x);// Negates elements of a SparseVector  
    SparseVector& operator =(const SparseVector& x);// Assigns one SparseVector to another
    friend ostream& operator<<(ostream& os, const SparseVector& x); //Sends contents of a SparseVector to a std::ostream object.

    friend double dot(const SparseVector& x , const SparseVector& y); //Calculates the dot product(inner product) of two SparseVectors
};


#endif