#ifndef ROOMBA_H
#define ROOMBA_H

#include"Robot.h"
#include"Bulldozer.h"
#include"Optimusprime.h"
#include"Robocop.h"
#include"Humanic.h"

#include<iostream>
#include<string>

using namespace std;

namespace PA4{

    class Optimusprime;
    class Robocop;
    class Bulldozer;

    class Roomba:public Robot
    {
    private:
    
        int Strength;

    public:

        Roomba();
        Roomba(int newStrength, int newHit);

        int getDamage();
        string get_type();

        
    };

    void Matches(Roomba& x, Roomba& y);
    void Matches(Roomba& x, Robocop& y);
    void Matches(Roomba& x, Optimusprime& y);
    void Matches(Roomba& x, Bulldozer& y);
};

#endif