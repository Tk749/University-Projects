#ifndef ROBOCOP_H
#define ROBOCOP_H

#include<iostream>
#include<string>

#include"Robot.h"
#include"Roomba.h"
#include"Optimusprime.h"
#include"Bulldozer.h"
#include"Humanic.h"

using namespace std;

namespace PA4{

    class Optimusprime;
    class Roomba;
    class Bulldozer;

    class Robocop: public Humanic{

    public:
        Robocop();
        Robocop(int newStrength, int newHit);

        int getDamage();
        string get_type();

    private:
        int Strength;

    };

    void Matches(Robocop& x, Roomba& y);
    void Matches(Robocop& x, Robocop& y);
    void Matches(Robocop& x, Optimusprime& y);
    void Matches(Robocop& x, Bulldozer& y);

};

#endif