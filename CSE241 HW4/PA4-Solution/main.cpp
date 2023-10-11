#include<iostream>
#include"Robot.h"
#include"Roomba.h"
#include"Bulldozer.h" 
#include "Humanic.h"
#include "Robocop.h"
#include "Optimusprime.h"


using namespace std;
using namespace PA4;


int main(){
    char c;
    int n= 0;
    Roomba roomba1(75,500);
    Roomba roomba2(250,750);
    Robocop robocop1(25,150);
    Robocop robocop2(15,275);
    Optimusprime optimusprime1(1,100);
    Optimusprime optimusprime2(55,975);
    Bulldozer bulldozer1(12,25000);
    Bulldozer bulldozer2(12,120);

    cout << "Match list" << endl << "1- Roomba(75,500) Vs Optimusprime(55,975)" << endl
    << "2- Robocop(1)(25,150) Vs Robocop(2)(15,275)" << endl
    << "3- Roomba(250,750) Vs Bulldozer(25,25000)" << endl
    << "4- Optimusprime(1,100) Vs Bulldozer(12,120)" << endl << endl;

    

    cout << "Press any key to continue" << endl << endl;
    cin >> c;

    cout << "First match " << "---> Roomba(75,500) Vs Optimusprime(55,975)" << endl << endl;

    Matches(roomba1,optimusprime2);

    cout<<"First match end"<<endl<<endl;



    cout << "Press any key to continue" << endl << endl;
    cin >> c;

    cout << "Second match " << "---> Roomba(75,500) Vs Optimusprime(55,975)" << endl << endl;

    Matches(robocop1,robocop2);

    cout<< endl << "Second match end"<<endl<<endl;



    cout << "Press any key to continue" << endl << endl;
    cin >> c;

    cout << "Third match " << "---> Roomba(75,500) Vs Optimusprime(55,975)" << endl << endl;

    Matches(roomba2,bulldozer1);

    cout<< endl << "Third match end"<<endl<<endl;


    cout << "Press any key to continue" << endl << endl;
    cin >> c;

    cout << "Fourth match " <<  "---> Roomba(75,500) Vs Optimusprime(55,975)" << endl << endl;

    Matches(optimusprime1,bulldozer2);

    cout<< endl << "Fourth match end"<<endl<<endl;


}