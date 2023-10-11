#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include<iostream>
#include<string>

#include"Robot.h"
#include"Roomba.h"
#include"Robocop.h"
#include"Bulldozer.h"
#include"Humanic.h"


using namespace std;

namespace PA4{

    class Roomba;
    class Robocop;
    class Bulldozer;

    class Optimusprime: public Humanic
    {
    public:
    
        Optimusprime();
        Optimusprime(int newStrength, int newHit);

        int getDamage();
        string get_type();
        
    private:
        int Strength;
    };

    void Matches(Optimusprime& x, Roomba& y);
    void Matches(Optimusprime& x, Robocop& y);
    void Matches(Optimusprime& x, Optimusprime& y);
    void Matches(Optimusprime& x, Bulldozer& y);

};

#endif