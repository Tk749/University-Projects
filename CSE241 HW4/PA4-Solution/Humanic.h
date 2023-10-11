#ifndef HUMANIC_H_
#define HUMANIC_H_

#include<iostream>
#include<string>
#include "Robot.h"

using namespace std;

namespace PA4{

    class Humanic: public Robot{

    public:
        Humanic();
        Humanic(int newStrength, int newHit);

        int getDamage_Humanic(); // Returns the damage caused by the humanic trait

    private:
        int Strength;
    };

};

#endif