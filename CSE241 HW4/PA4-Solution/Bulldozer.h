#ifndef BULLDOZER_H
#define BULLDOZER_H

#include<iostream>
#include<string>

#include"Robot.h"
#include"Roomba.h"
#include"Robocop.h"
#include"Optimusprime.h"
#include"Humanic.h"


using namespace std;

namespace PA4{

    class Optimusprime;
    class Roomba;
    class Robocop;

    class Bulldozer: public Robot
    {
    public:

        Bulldozer();
        Bulldozer(int newStrength, int newHit);

        int getDamage(); // returns total damage of bulldozer
        string get_type();
        
    private:

        int Strength;
    };


    void Matches(Bulldozer& x, Roomba& y);//fighting simulation
    void Matches(Bulldozer& x, Robocop& y);//fighting simulation
    void Matches(Bulldozer& x, Optimusprime& y);//fighting simulation
    void Matches(Bulldozer& x, Bulldozer& y);//fighting simulation

};

#endif