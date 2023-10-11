#include <iostream>
#include <cstdlib>
#include "Robot.h"  
#include "Humanic.h"   


using namespace std;

namespace PA4{


    Humanic::Humanic():Strength(10){}
    Humanic::Humanic(int newStrength, int newHit)
    :Robot(newStrength,newHit),Strength(newStrength){}

    int Humanic::getDamage_Humanic(){ // Returns the damage caused by the humanic trait

        int chance = rand() % 10;

        if(chance == 7){

            return 50;
        }
        else{

            return 0;
        }
    }
};